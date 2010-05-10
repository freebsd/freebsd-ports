# New ports collection makefile for:	free-sa-devel
# Date created:				27 Jul 2009
# Whom:					Alexander Moisseev <moiseev@mezonplus.ru>
#
# $FreeBSD$
#

PORTNAME=	free-sa
PORTVERSION=	2.0.0b3
CATEGORIES=	www
MASTER_SITES=	SF
MASTER_SITE_SUBDIR=	free-sa/free-sa-dev/2.0.0b3/
PKGNAMESUFFIX=	-devel

MAINTAINER=	moiseev@mezonplus.ru
COMMENT=	Statistic analyzer for daemons log files similar to SARG

MAKE_JOBS_SAFE=	yes
CONFLICTS=	free-sa-[0-9]*
LATEST_LINK=	free-sa-devel

WWWDIR?=	${PREFIX}/www/${PORTNAME}
DOCSDIR=	${PREFIX}/share/doc/${PORTNAME}-${DISTVERSION}

PORTDOCS=	COPYING ChangeLog FAQ INSTALL README README.DEV THANKS
MAN1=		free-sa.1
MAN5=		free-sa.conf.5

MAKE_ARGS+=	PREFIX="${PREFIX}" \
		ETCDIR="${ETCDIR}" \
		WWWDIR="${WWWDIR}" \
		CACHEDIR="/var/cache/${PORTNAME}" \
		LOCDIR="${DATADIR}" \
		DOCDIR="${DOCSDIR}" \
		LOGFILE=/var/log/squid/access.log \
		CC="${CC}" \
		SORT=/usr/bin/sort \
		INSTALL=/usr/bin/install \
		LARGEFILE=yes \
		SATSEP="'" \
		HAVE_STRL="1"\
		ADDLDFLAGS="${LDFLAGS} --relax -mrelax"

OPTIONS=	OPTIMIZED_CFLAGS "Build with distribution-recommended CFLAGS"	off \
		SA_DEBUG "Enable Free-SA debugging (level 1)"	off

.include <bsd.port.options.mk>

pre-everything::
.ifndef(WITH_OPTIMIZED_CFLAGS)
	@${ECHO_MSG} ">>> This software is computationally demanding, and users are"
	@${ECHO_MSG} ">>> advised to employ compiler optimizations when building it."
	@${ECHO_MSG} ">>> Author of this software have used such flags as"
	@${ECHO_MSG} ">>> 'CFLAGS= -O4 -pipe -march=native' and 'CC= gcc' to advantage."
	@${ECHO_MSG} ">>> You can set them in make.conf, but they depends on your system and compiler."
	@${ECHO_MSG} ">>> In addition, you can enable extra flags by defining WITH_OPTIMIZED_CFLAGS"
	@${ECHO_MSG} ">>> For example, 'make WITH_OPTIMIZED_CFLAGS=yes'"
	@${ECHO_MSG} ">>>"
.endif
.ifndef(WITH_SA_DEBUG) && (SA_DEBUG_LEVEL)
	@${ECHO_MSG} ">>> You can enable Free-SA debugging (level 1) by defining WITH_SA_DEBUG"
	@${ECHO_MSG} ">>> For example, 'make WITH_SA_DEBUG=yes'"
	@${ECHO_MSG} ">>> Or for specific level (0-7) you can use SA_DEBUG_LEVEL"
	@${ECHO_MSG} ">>> For example, 'make SA_DEBUG_LEVEL=4'"
	@${ECHO_MSG} ">>> Note that SA_DEBUG_LEVEL overrides WITH_SA_DEBUG"
	@${ECHO_MSG} ">>>"
.endif

.if defined(WITH_SA_DEBUG)
SA_DEBUG_LEVEL?=	1
.else
SA_DEBUG_LEVEL?=	0
.endif

.if defined(NOPORTDOCS)
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-Makefile
.endif

post-patch:
	@${REINPLACE_CMD} \
		-e 's,^DEBUG = .*,DEBUG = ${SA_DEBUG_LEVEL},' \
		-e 's,^include .(GMKPATH)/configs/.(OSTYPE)\.mk,,' \
		${WRKSRC}/global.mk

.if defined(WITH_OPTIMIZED_CFLAGS)
MAKE_ARGS+=	ADDCFLAGS="${CFLAGS} \
		-fomit-frame-pointer \
		-std=c99 \
		-W -Wall -Wextra -Wredundant-decls -Wnested-externs -Wstrict-prototypes \
		-Wmissing-prototypes -Wpointer-arith -Winline -Wcast-qual \
		-Wreturn-type -Wswitch -Wshadow -Wcast-align -Wuninitialized \
		-Wchar-subscripts -Wuninitialized -Wbad-function-cast -Wwrite-strings"
.else
MAKE_ARGS+=	ADDCFLAGS="${CFLAGS}"
.endif

.include <bsd.port.mk>
