# New ports collection makefile for:	gld
# Date created:				15 Jul 2004
# Whom:					Blaz Zupan <blaz@si.FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gld
PORTVERSION=	1.4
CATEGORIES=	mail
MASTER_SITES=	http://www.gasmi.net/down/
EXTRACT_SUFX=	.tgz

MAINTAINER=	blaz@si.FreeBSD.org
COMMENT=	Greylisting daemon for Postfix

USE_MYSQL=	yes
USE_REINPLACE=	yes
USE_RC_SUBR=	yes
HAS_CONFIGURE=	yes

CONFIGURE_ARGS+=	--with-mysql=${PREFIX}

PKGMESSAGE=	${WRKDIR}/MESSAGE

SED_SCRIPT=	-e 's,%%DOCSDIR%%,${DOCSDIR},g' \
		-e 's,%%PREFIX%%,${PREFIX},g' \
		-e 's,%%RC_SUBR%%,${RC_SUBR},g'

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
.for FILE in HISTORY LICENCE README tables.sql
	${INSTALL_DATA} ${WRKSRC}/${FILE} ${DOCSDIR}
.endfor
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
