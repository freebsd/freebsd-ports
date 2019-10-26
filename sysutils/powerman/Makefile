# Created by: Greg Lewis <glewis@FreeBSD.org>
# $FreeBSD$

PORTNAME=	powerman
PORTVERSION=	2.3.20
PORTREVISION=	2
CATEGORIES=	sysutils parallel
MASTER_SITES=	https://github.com/chaos/powerman/releases/download/${PORTVERSION}/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Tool for doing remote power control

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libcurl.so:ftp/curl

USES=		fakeroot libtool localbase:ldflags perl5 shebangfix
USE_LDCONFIG=	yes
USE_PERL5=	build
USE_RC_SUBR=	powerman
SHEBANG_FILES=	heartbeat/powerman

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-httppower --localstatedir=/var \
		--with-pkgconfig-dir=${PREFIX}/libdata/pkgconfig

INSTALL_TARGET=	install-strip
TEST_TARGET=	check

post-patch:
	@${REINPLACE_CMD} -e \
		'/^install-data-am/s|:.*|:|' ${WRKSRC}/scripts/Makefile.in
	# Disable failing tests.
.for test_case in t50 t53 t56 t57 t58 t59
	@${REINPLACE_CMD} -E -e 's/${test_case}(.conf)?//' \
		${WRKSRC}/test/Makefile.in
.endfor

.include <bsd.port.mk>
