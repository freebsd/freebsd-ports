PORTNAME=	irrtoolset
DISTVERSIONPREFIX=	release-
DISTVERSION=	5.1.3
PORTREVISION=	2
CATEGORIES=	net-mgmt

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Suite of routing policy tools to interact with the IRR
WWW=		https://github.com/irrtoolset/irrtoolset

LICENSE=	MIT GPLv2+ RIPE_NCC
LICENSE_COMB=	multi
LICENSE_NAME_RIPE_NCC=	RIPE NCC license
LICENSE_FILE=	${WRKSRC}/COPYING
LICENSE_PERMS_RIPE_NCC=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

USES=		autoreconf bison gmake libtool
GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share
USE_GITHUB=	yes

PLIST_FILES=	bin/rpslcheck bin/peval bin/rtconfig \
		share/man/man1/rtconfig.1.gz share/man/man1/peval.1.gz \
		share/man/man1/rpslcheck.1.gz share/man/man1/irrtoolset-errors.1.gz

.include <bsd.port.options.mk>

.if ${OPSYS} == FreeBSD && ( ${OSVERSION} >= 1400091 || ( ${OSVERSION} >= 1302507 && ${OSVERSION} < 1400000 ))
CFLAGS+=  -Dregister=
.endif

.include <bsd.port.mk>
