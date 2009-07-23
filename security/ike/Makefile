# New ports collection makefile for:	ike
# Date created:		24 march 2007
# Whom:			mgrooms@shrew.net
#
# $FreeBSD$
#

PORTNAME=	ike
PORTVERSION=	2.1.4
CATEGORIES=	security net
MASTER_SITES=	http://www.shrew.net/download/ike/
DISTNAME=	${PORTNAME}-${PORTVERSION}-release
EXTRACT_SUFX=	.tbz2

MAINTAINER=	mgrooms@shrew.net
COMMENT=	Shrew Soft IKE daemon and client tools

ONLY_FOR_ARCHS=	i386 amd64

USE_BISON=	build
USE_OPENSSL=	yes
USE_CMAKE=	yes
USE_BZIP2=	yes
USE_LDCONFIG=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}

OPTIONS=	QTGUI		"Enable QT client front end applications" on \
		NATT		"Enable NAT-Traversal (kernel-patch required)" off \
		LDAP		"Enable LDAP XAuth daemon support" off \
		DEBUG		"Enable Debug support" off

MAN1=		ikea.1 ikec.1
MAN5=		iked.conf.5
MAN8=		iked.8

.include <bsd.port.pre.mk>

.ifdef(WITH_DEBUG)
CMAKE_ARGS+=	-DDEBUG=YES
.endif

.ifdef(WITH_LDAP)
USE_OPENLDAP=	YES
CMAKE_ARGS+=	-DLDAP=YES
.endif

.ifdef(WITH_NATT)
CMAKE_ARGS+=	-DNATT=YES
.endif

.ifdef(WITH_QTGUI)
CMAKE_ARGS+=	-DQTGUI=YES
LIB_DEPENDS+=	qt-mt:${PORTSDIR}/x11-toolkits/qt33
.endif

post-patch:
.ifdef(WITH_NATT)
	@${ECHO_MSG} "===> -------------------------------------------------------------------------"
	@${ECHO_MSG} "===> ATTENTION: You need a kernel patch to enable NAT-Traversal functionality!"
. if ${OSVERSION} < 600000
	@${ECHO_MSG} "===>     There is no known NAT-T patch for FreeBSD 1 - 5!!!"
. endif
. if ${OSVERSION} > 600000 && ${OSVERSION} < 699999
	@${ECHO_MSG} "===>     http://ipsec-tools.sf.net/freebsd6-natt.diff"
. endif
. if ${OSVERSION} > 700000 && ${OSVERSION} < 799999
	@${ECHO_MSG} "===>     http://vanhu.free.fr/FreeBSD/patch-natt-freebsd7-2007-10-22.diff"
. endif
. if ${OSVERSION} > 800000
	@${ECHO_MSG} "===>     http://vanhu.free.fr/FreeBSD/patch-natt-freebsd-HEAD-2007-10-22.diff"
. endif
	@${ECHO_MSG} "===> You might possibly have to do some steps manually if it fails to apply."
	@${ECHO_MSG} "===> -------------------------------------------------------------------------"

	@sleep 3
.endif

post-build:
# QT 3.3 UIC (User Interface Compiler) creates these, so remove them.
# Otherwise x11-toolkits/qt33 would have to be patched, as Gentoo did.
.for f in .qt_plugins_* qt_plugins_*
	@${RM} -f ${LOCALBASE}/etc/settings/${f}
.endfor
	@${RMDIR} ${LOCALBASE}/etc/settings || ${TRUE}

post-install:
	@if ! ${SYSCTL} -a | ${GREP} -q ipsec; then \
	${ECHO_MSG} "WARNING: IPsec feature is disabled on this host"; \
	${ECHO_MSG} "         You must configure a kernel with this option to use this software"; \
	fi ;

.include <bsd.port.post.mk>
