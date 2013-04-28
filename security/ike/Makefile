# Created by: mgrooms@shrew.net
# $FreeBSD$

PORTNAME=	ike
PORTVERSION=	2.1.7
PORTREVISION=	1
CATEGORIES=	security net
MASTER_SITES=	http://www.shrew.net/download/ike/
DISTNAME=	${PORTNAME}-${PORTVERSION}-release
EXTRACT_SUFX=	.tbz2

MAINTAINER=	mgrooms@shrew.net
COMMENT=	Shrew Soft IKE daemon and client tools

ONLY_FOR_ARCHS=	i386 amd64

USE_RC_SUBR=	iked
USES=		bison cmake
USE_OPENSSL=	yes
USE_BZIP2=	yes
USE_LDCONFIG=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}

CMAKE_ARGS+=	-DETCDIR:PATH="${PREFIX}/etc" \
		-DLIBDIR:PATH="${PREFIX}/lib" \
		-DMANDIR:PATH="${PREFIX}/man"

OPTIONS_DEFINE=	QTGUI NATT LDAP DEBUG
QTGUI_DESC=	Enable QT client front end applications
NATT_DESC=	Enable NAT-Traversal (kernel-patch required)
LDAP_DESC=	Enable LDAP XAuth daemon support

.include <bsd.port.options.mk>

MAN5=		iked.conf.5
MAN8=		iked.8

.if ${PORT_OPTIONS:MDEBUG}
CMAKE_ARGS+=	-DDEBUG=YES
.endif

.if ${PORT_OPTIONS:MLDAP}
USE_OPENLDAP=	YES
CMAKE_ARGS+=	-DLDAP=YES
.endif

.if ${PORT_OPTIONS:MNATT}
CMAKE_ARGS+=	-DNATT=YES
.endif

.if ${PORT_OPTIONS:MQTGUI}
CMAKE_ARGS+=	-DQTGUI=YES
USE_QT_VER=	3
MAN1=		ikea.1 ikec.1
PLIST_SUB+=	QTGUI=""
.else
PLIST_SUB+=	QTGUI="@comment "
.endif

.include <bsd.port.pre.mk>

post-patch:
.if ${PORT_OPTIONS:MNATT}
. if ${OSVERSION} < 800000
	@${ECHO_MSG} "===> -------------------------------------------------------------------------"
	@${ECHO_MSG} "===> WARNING: You will need to patch your kernel for NAT-T functionality!"
	@${ECHO_MSG} "===>   http://people.freebsd.org/~vanhu/NAT-T/patch-natt-7.2-2009-05-12.diff"
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
.if ${PORT_OPTIONS:MNATT}
	@${ECHO_MSG} "===> -------------------------------------------------------------------------"
	@${ECHO_MSG} "===> WARNING: To use NAT Traversal ( NAT-T ) support, please be sure to"
	@${ECHO_MSG} "===> include the following line in your kernel config file."
	@${ECHO_MSG} "===>   options IPSEC_NAT_T"
	@${ECHO_MSG} "===> -------------------------------------------------------------------------"
.endif

.include <bsd.port.post.mk>
