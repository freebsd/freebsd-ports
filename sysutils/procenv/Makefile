# Created by: James Hunt <james.hunt@ubuntu.com>
# $FreeBSD$

PORTNAME=	procenv
PORTVERSION=	0.32
CATEGORIES=	sysutils
MASTER_SITES=	https://launchpad.net/procenv/trunk/${PORTVERSION}/+download/ \
		DEBIAN \
		http://people.canonical.com/~jhunt/debian/procenv/

MAINTAINER=	james.hunt@ubuntu.com
COMMENT=	Utility to show process environment

LICENSE=	GPLv3

BUILD_DEPENDS=	xmlwf:${PORTSDIR}/textproc/expat2

GNU_CONFIGURE=	yes
USES=		gmake
USE_AUTOTOOLS=	aclocal automake
USE_PERL5_BUILD=yes

PLIST_FILES=	bin/procenv \
		man/man1/procenv.1.gz

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 800505
BROKEN=		does not build on old ${OPSYS} versions
.endif

# Test to ensure procenv will actually run.
#
# This has the attractive side-effect of displaying the environment
# of the build system which may be of interest to those fixing FTBFS
# packages that build correctly locally.
regression-test: build
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} check

test: regression-test

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/procenv

.include <bsd.port.post.mk>
