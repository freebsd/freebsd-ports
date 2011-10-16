# New ports collection makefile for:	ike
# Date created:		24 march 2007
# Whom:			mgrooms@shrew.net
#
# $FreeBSD$
#

PORTNAME=	ike
PORTVERSION=	2.1.7
CATEGORIES=	security net
MASTER_SITES=	http://www.shrew.net/download/ike/
DISTNAME=	${PORTNAME}-${PORTVERSION}-release
EXTRACT_SUFX=	.tbz2

MAINTAINER=	mgrooms@shrew.net
COMMENT=	Shrew Soft IKE daemon and client tools

ONLY_FOR_ARCHS=	i386 amd64

USE_RC_SUBR=	iked
USE_BISON=	build
USE_OPENSSL=	yes
USE_CMAKE=	yes
USE_BZIP2=	yes
USE_LDCONFIG=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}

CMAKE_ARGS+=	-DETCDIR:PATH="${PREFIX}/etc" \
		-DLIBDIR:PATH="${PREFIX}/lib" \
		-DMANDIR:PATH="${PREFIX}/man"

OPTIONS=	QTGUI		"Enable QT client front end applications" on \
		NATT		"Enable NAT-Traversal (kernel-patch required)" off \
		LDAP		"Enable LDAP XAuth daemon support" off \
		DEBUG		"Enable Debug support" off

.include <bsd.port.options.mk>

MAN5=		iked.conf.5
MAN8=		iked.8

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
USE_QT_VER=	3
MAN1=		ikea.1 ikec.1
PLIST_SUB+=	QTGUI=""
.else
PLIST_SUB+=	QTGUI="@comment "
.endif

.include <bsd.port.pre.mk>

post-patch:
.if defined(WITH_NATT)
. if ${OSVERSION} < 800000
	@${ECHO_MSG} "===> -------------------------------------------------------------------------"
	@${ECHO_MSG} "===> WARNING: You will need to patch your kernel for NAT-T functionality!"
.  if ${OSVERSION} < 600000
	@${ECHO_MSG} "===>   There is no known NAT-T patch for FreeBSD 1 - 5!!!"
.  endif
.  if ${OSVERSION} > 600000 && ${OSVERSION} < 699999
	@${ECHO_MSG} "===>   http://ipsec-tools.sf.net/freebsd6-natt.diff"
.  endif
.  if ${OSVERSION} > 700000 && ${OSVERSION} < 799999
	@${ECHO_MSG} "===>   http://people.freebsd.org/~vanhu/NAT-T/patch-natt-7.2-2009-05-12.diff"
.  endif
	@${ECHO_MSG} "===> You may need to edit the patch if it fails to apply cleanly."
	@${ECHO_MSG} "===> -------------------------------------------------------------------------"
	@sleep 3
. endif
.endif
	@${REINPLACE_CMD} -e 's,/usr/local,${LOCALBASE},' \
		${WRKSRC}/CMakeLists.txt

post-build:
# QT 3.3 UIC (User Interface Compiler) creates these, so remove them.
# Otherwise x11-toolkits/qt33 would have to be patched, as Gentoo did.
.for f in .qt_plugins_* qt_plugins_*
	@${RM} -f ${LOCALBASE}/etc/settings/${f}
.endfor
	@${RMDIR} ${LOCALBASE}/etc/settings || ${TRUE}

post-install:
	@if ! ${SYSCTL} -a | ${GREP} -q ipsec; then \
	${ECHO_MSG} "===> -------------------------------------------------------------------------"; \
	${ECHO_MSG} "===> WARNNG: You need IPsec support in your kernel, please see:"; \
	${ECHO_MSG} "===>   http://www.freebsd.org/doc/en/books/handbook/ipsec.html"; \
	${ECHO_MSG} "===> -------------------------------------------------------------------------"; \
	fi ;
.if defined(WITH_NATT)
	@${ECHO_MSG} "===> -------------------------------------------------------------------------"
	@${ECHO_MSG} "===> WARNING: To use NAT Traversal ( NAT-T ) support, please be sure to"
	@${ECHO_MSG} "===> include the following line in your kernel config file."
	@${ECHO_MSG} "===>   options IPSEC_NAT_T"
	@${ECHO_MSG} "===> -------------------------------------------------------------------------"
.endif

.include <bsd.port.post.mk>
