# New ports collection makefile for:	openvpn
# Date created:		2002-06-23
# Whom:			Matthias Andree <matthias.andree@gmx.de>
#
# $FreeBSD$
#

PORTNAME=	openvpn
DISTVERSION=	2.0.1
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	http://openvpn.net/release/

MAINTAINER=	matthias.andree@gmx.de
COMMENT=	Secure IP/Ethernet tunnel daemon

GNU_CONFIGURE=	yes
USE_OPENSSL=	yes
CONFIGURE_TARGET=	--build=${ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ARGS=	--with-lzo-lib=${LOCALBASE}/lib \
		--with-lzo-headers=${LOCALBASE}/include

MAN8=		openvpn.8

OPTIONS=	PW_SAVE "Interactive passwords may be read from a file" off

USE_RC_SUBR=	openvpn.sh

SUB_FILES=	pkg-message

.include <bsd.port.pre.mk>

# NOTE: there is no way to explicitly specify the LZO version to OpenVPN,
# if LZO2 and LZO1 are installed, OpenVPN will pick LZO2.
# So depend on LZO1 only if it's already there and LZO2 isn't.
# PACKAGE_BUILDING will also force LZO2.
.if exists(${LOCALBASE}/lib/liblzo2.so.2) || !exists(${LOCALBASE}/lib/liblzo.so.1) || defined(PACKAGE_BUILDING)
LIB_DEPENDS=	lzo2.2:${PORTSDIR}/archivers/lzo2
.else
LIB_DEPENDS=	lzo.1:${PORTSDIR}/archivers/lzo
.endif

.if defined(WITH_PW_SAVE)
CONFIGURE_ARGS+=	--enable-password-save
.endif

# self-tests here
post-build:
	cd ${WRKSRC} && ${MAKE} check

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for docs in AUTHORS COPYING COPYRIGHT.GPL ChangeLog INSTALL NEWS \
	PORTS README
	${INSTALL_DATA} ${WRKSRC}/${docs} ${DOCSDIR}
.endfor
	( cd ${WRKSRC} \
	&& ${FIND} easy-rsa sample-config-files sample-scripts -depth \
	| ${GREP} -v easy-rsa/Windows \
	| ${CPIO} -pdmu ${DOCSDIR} )
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
