# Created by: ijliao
# $FreeBSD$

PORTNAME=	swish++
PORTVERSION=	6.1.5
PORTREVISION=	3
CATEGORIES=	www textproc
MASTER_SITES=	SF/swishplusplus/swishplusplus/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Simple Web Indexing System for Humans: C++ version

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/Copying

RUN_DEPENDS=	wget:ftp/wget

USES=		gmake perl5 shebangfix
SHEBANG_FILES=	scripts/searchc.in scripts/splitmail.in scripts/httpindex.in
perl_OLD_CMD=	%%PERL%%
MAKEFILE=	GNUmakefile
MAKE_ENV=	PERL="${PERL}"

post-patch:
	@${REINPLACE_CMD} -e '/^#error/d' ${WRKSRC}/config.h
.for i in scripts/searchd scripts/searchmonitor
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|g' ${WRKSRC}/${i}.in
.endfor

do-configure:
	@(cd ${WRKSRC}/config && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} \
		${MAKE_FLAGS} ${MAKEFILE})

pre-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/${SITE_PERL_REL}

post-install:
	(cd ${FILESDIR} && ${INSTALL_SCRIPT} swish++.sh \
		${STAGEDIR}${PREFIX}/etc/rc.d/swish++.sh.sample)

.include <bsd.port.mk>
