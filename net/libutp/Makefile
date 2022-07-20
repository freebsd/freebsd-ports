PORTNAME=	bittorrent-libutp
PORTVERSION=	0.20130514
PORTREVISION=	1
CATEGORIES=	net devel

MAINTAINER=	mi@aldan.algebra.com
COMMENT=	The uTorrent Transport Protocol library and sample utilities

LICENSE=	MIT

USE_GITHUB=	yes
GH_ACCOUNT=	${PORTNAME:C/-.*//}
GH_PROJECT=	${PORTNAME:C/.*-//}
GH_TAGNAME=	7c4f19a

USES=		dos2unix uidfix
MAKEFILE=	${FILESDIR}/BSDmakefile
USE_LDCONFIG=	yes

pre-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/include/libutp

post-build:
	${MAKE} -f ${FILESDIR}/BSDmakefile.utils -C ${WRKSRC}/utp_file PROG_CXX=utp_send
	${MAKE} -f ${FILESDIR}/BSDmakefile.utils -C ${WRKSRC}/utp_file PROG_CXX=utp_recv
	${MAKE} -f ${FILESDIR}/BSDmakefile.utils -C ${WRKSRC}/utp_test PROG_CXX=utp_test

post-install:
	${INSTALL_PROGRAM}	\
	    ${WRKSRC}/utp_file/utp_send	\
	    ${WRKSRC}/utp_file/utp_recv	\
	    ${WRKSRC}/utp_test/utp_test \
		${STAGEDIR}${PREFIX}/bin/

.include <bsd.port.mk>
