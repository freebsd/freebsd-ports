PORTNAME=	libnet
PORTVERSION=	1.2
PORTEPOCH=	1
CATEGORIES=	net
MASTER_SITES=	https://github.com/libnet/libnet/releases/download/v${PORTVERSION}/

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	C library for creating IP packets

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cpe libtool

CONFIGURE_ARGS=	--disable-doxygen-doc --disable-doxygen-dot --disable-doxygen-html --disable-doxygen-man
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes

CPE_VENDOR=	libnet_project

OPTIONS_DEFINE=	BPF DOCS EXAMPLES
OPTIONS_DEFAULT=BPF
BPF_DESC=	link layer bpf

BPF_CONFIGURE_OFF=	--with-link-layer=none
BPF_CONFIGURE_ON=	--with-link-layer=bpf

post-install-EXAMPLES-on:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/
	${INSTALL_DATA} ${WRKSRC}/sample/*.c ${STAGEDIR}${EXAMPLESDIR}/

.include <bsd.port.mk>
