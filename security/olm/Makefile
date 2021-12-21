PORTNAME=	olm
DISTVERSIONPREFIX=
DISTVERSION=	3.2.6
CATEGORIES=	security
MASTER_SITES=	https://gitlab.matrix.org/matrix-org/olm/-/archive/${DISTVERSION}/

MAINTAINER=	adridg@FreeBSD.org
COMMENT=	Double Ratchet cryptographic ratchet in C++

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake compiler:c++11-lang cpe \
		localbase:ldflags tar:bz2

CPE_VENDOR=	matrix

.include <bsd.port.mk>
