# New ports collection makefile for:	gld
# Date created:				15 Jul 2004
# Whom:					Blaz Zupan <blaz@si.FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gld
PORTVERSION=	1.5.2
CATEGORIES=	mail
MASTER_SITES=	http://www.gasmi.net/down/
EXTRACT_SUFX=	.tgz

MAINTAINER=	blaz@si.FreeBSD.org
COMMENT=	Greylisting daemon for Postfix

USE_REINPLACE=	yes
USE_RC_SUBR=	yes
HAS_CONFIGURE=	yes

PKGMESSAGE=	${WRKDIR}/MESSAGE

OPTIONS=	MYSQL   "MySQL support"         on \
		PGSQL   "PgSQL support"         off

SED_SCRIPT=	-e 's,%%DOCSDIR%%,${DOCSDIR},g' \
		-e 's,%%PREFIX%%,${PREFIX},g' \
		-e 's,%%RC_SUBR%%,${RC_SUBR},g'

.include <bsd.port.pre.mk>

.if defined(WITH_MYSQL) && defined(WITH_PGSQL)
BROKEN=		"Cannot compile with both MySQL and PgSQL support"
.endif

.if defined(WITH_MYSQL)
CONFIGURE_ARGS+=	--with-mysql=${PREFIX}
USE_MYSQL=	yes
.endif

.if defined(WITH_PGSQL)
CONFIGURE_ARGS+=	--with-pgsql=${PREFIX}
USE_PGSQL=	yes
.endif

pre-build:
	${REINPLACE_CMD} -e 's,"/etc/gld.conf","${PREFIX}/etc/gld.conf",' ${WRKSRC}/gld.h
	for f in gld.sh MESSAGE; do \
		${SED} ${SED_SCRIPT} < ${FILESDIR}/$${f}.tmpl >> ${WRKDIR}/$${f}; \
	done

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gld ${PREFIX}/sbin
	${INSTALL_DATA} ${WRKSRC}/gld.conf ${PREFIX}/etc/gld.conf-dist
	${INSTALL_SCRIPT} ${WRKDIR}/gld.sh ${PREFIX}/etc/rc.d
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for FILE in HISTORY LICENCE README table-whitelist.sql tables.mysql tables.pgsql
	${INSTALL_DATA} ${WRKSRC}/${FILE} ${DOCSDIR}
.endfor
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
