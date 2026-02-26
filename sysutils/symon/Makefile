PORTNAME=	symon
DISTVERSION=	2.90
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	https://wpd.home.xs4all.nl/symon/philes/

MAINTAINER=	jamie@catflap.org
COMMENT=	Performance and information monitoring tool
WWW=		https://wpd.home.xs4all.nl/symon/

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		groff perl5 shebangfix
USE_PERL5=	build

SHEBANG_FILES=	client/getsymonitem.pl

MAKE_ARGS=	EXADIR="etc" \
		LORDER=echo \
		MANDIR="share/man" \
		PREFIX="${STAGEDIR}${PREFIX}" \
		RRDDIR="${LOCALBASE}" \
		SYSCONFDIR="${PREFIX}/etc" \
		SUBDIR="lib ${SUBDIR} client" \
		TSORT=cat

MAKE_JOBS_UNSAFE=	yes

CFLAGS+=	-D_WANT_SEMUN

EXTRACT_AFTER_ARGS=	--strip-components 1 \
			--no-same-owner --no-same-permissions
SUB_FILES=	pkg-message

NO_WRKSUBDIR=	yes

USERS=		_symon
GROUPS=		_symon

PORTDOCS=	CHANGELOG HACKERS TODO

OPTIONS_DEFINE=		DOCS
OPTIONS_DEFAULT=	SYMON SYMUX
OPTIONS_MULTI=		MODULES
OPTIONS_MULTI_MODULES=	SYMON SYMUX
OPTIONS_SUB=		yes

MODULES_DESC=		Modules
SYMON_DESC=		Include symon(8) system monitor.
SYMUX_DESC=		Include symon stream multiplexer [symux(8)]

SYMON_VARS=		SUBDIR+=symon \
			USE_RC_SUBR+=symon
SYMUX_LIB_DEPENDS=	librrd.so:databases/rrdtool
SYMUX_VARS=		SUBDIR+=symux \
			USE_RC_SUBR+=symux

.include <bsd.port.pre.mk>

post-patch:
# We need to teach symon about mbstat changes/removal in r253351 and r253361.
	@${RM} ${WRKSRC}/platform/FreeBSD/sm_mbuf.c
# We need to teach symon about pf API changes from FreeBSD 15 onwards.

# Until someone can update sm_pf.c to use the nvlist variants, remove it
# from FreeBSD 15 installs, as it no longer works due to the removal of
# DIOCGETSTATUS. Patches welcome!
# See https://lists.freebsd.org/archives/freebsd-pf/2023-April/000345.html
# Subject: pf: remove DIOCGETRULE and DIOCGETSTATUS
# Author: Kristof Provost <kp@FreeBSD.org>
# Date: 2023-08-29 15:17:24 +0000
# Link: https://cgit.freebsd.org/src/commit/?id=8d49fd7331bc72671a14f1aac1d9cdea36672d19
.if (${OPSYS} == FreeBSD) && ${OSVERSION} >= 1500000
	@${RM} ${WRKSRC}/platform/FreeBSD/sm_pf.c
.endif

do-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} \
		${STAGEDIR}${DOCSDIR}

post-install-SYMON-on:
	${MV} ${STAGEDIR}${PREFIX}/etc/symon.conf \
		${STAGEDIR}${PREFIX}/etc/symon.conf.sample

post-install-SYMUX-on:
	${MV} ${STAGEDIR}${PREFIX}/etc/symux.conf \
		${STAGEDIR}${PREFIX}/etc/symux.conf.sample

.include <bsd.port.post.mk>
