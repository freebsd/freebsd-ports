# New ports collection makefile for:	openvpn
# Date created:		2002-06-23
# Whom:			Matthias Andree <matthias.andree@web.de>
#
# $FreeBSD$
#

PORTNAME=	openvpn
DISTVERSION=	2.0
PORTREVISION=	3
CATEGORIES=	security
MASTER_SITES=	http://openvpn.net/release/

MAINTAINER=	matthias.andree@gmx.de
COMMENT=	Secure IP/Ethernet tunnel daemon

LIB_DEPENDS=	lzo.1:${PORTSDIR}/archivers/lzo

GNU_CONFIGURE=	yes
USE_OPENSSL=	yes
CONFIGURE_TARGET=	--build=${ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ARGS=	--with-lzo-lib=${LOCALBASE}/lib \
		--with-lzo-headers=${LOCALBASE}/include

MAN8=		openvpn.8

# self-tests here
post-build:
	( set -e ; cd ${WRKSRC} && \
	./openvpn --genkey --secret key && \
	./openvpn --test-crypto --secret key && ${RM} key )
	( set -e ; cd ${WRKSRC} && { \
	./openvpn --config sample-config-files/loopback-server & \
	./openvpn --config sample-config-files/loopback-client ; \
	wait ; })

post-install:
	${INSTALL_SCRIPT} ${FILESDIR}/openvpn.sh.sample \
		${PREFIX}/etc/rc.d/openvpn.sh.sample
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

.include <bsd.port.mk>
