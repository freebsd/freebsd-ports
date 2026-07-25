PORTNAME=	liburcu
DISTVERSION=	0.15.6
CATEGORIES=	sysutils
MASTER_SITES=	https://lttng.org/files/urcu/
DISTNAME=	userspace-rcu-${DISTVERSION}

PATCH_SITES=	https://github.com/urcu/userspace-rcu/commit/
PATCHFILES=	16b21287ee99c4f79d49f1840dddb8cc050abee1.patch:-p1 \
		ca541c6b8c6ce1c166329fa1c19345d8f7794a5a.patch:-p1 \
		5c33a80edb016c2241cebabc07fc42698ee5d513.patch:-p1 \
		f240cba1dbadd0649f523953cd53fada508d82b5.patch:-p1 \
		d5ffaf362824a7cfeda8c7f0479bfb1c7688e65d.patch:-p1 \
		1f52ea43e6c0c07bd77886ef762a14e37fd42f89.patch:-p1 \
		7eb03ba629b3205696efaefaa51dd37b519ac128.patch:-p1

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Userspace read-copy-update (RCU) data synchronization library
WWW=		https://liburcu.org/

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/LICENSES/LGPL-2.1-or-later.txt

USES=		autoreconf libtool pathfix tar:bzip2
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes

TEST_TARGET=	check
INSTALL_TARGET=	install-strip

CONFIGURE_ENV=	ac_cv_prog_cc_g=no ac_cv_prog_cxx_g=no
CONFIGURE_ARGS=	--docdir=${DOCSDIR}

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
