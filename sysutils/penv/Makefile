# New ports collection makefile for:	penv
# Date created:		5 August 2001
# Whom:			roam@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	penv
PORTVERSION=	1.2.b1
CATEGORIES=	sysutils
MASTER_SITES=	http://devel.ringlet.net/sysutils/penv/
DISTNAME=	${PORTNAME}-${PORTVERSION:S/.b/pre/}

MAINTAINER=	roam@FreeBSD.org

RUN_DEPENDS=	envdir:${PORTSDIR}/sysutils/daemontools

MAN1=		penv.1
MANCOMPRESSED=	yes

CFLAGS_COMPAT=	-DHAVE_STRLCPY -DHAVE_FGETLN
MAKE_ENV+=	CFLAGS_COMPAT="${CFLAGS_COMPAT}"

.if		!defined(NO_RELEASE)
MAKE_ENV+=	RELEASE=yes
.endif

DBDIR?=		/var/db/${PORTNAME}

PLIST_SUB+=	DBDIR=${DBDIR}

HTMLDOCS=	docbook.css index.html penv-compat.html penv-history.html \
		penv-install.html penv-src.html penv-usage.html penv.html
HTMLCDOCS=	changes.html changes.txt
TXTDOCS=	penv.txt

post-install:
		${MKDIR} ${PREFIX}/etc
		${MKDIR} ${DBDIR}
		${INSTALL_DATA} ${WRKSRC}/penv.conf.default ${PREFIX}/etc
		if [ ! -e ${PREFIX}/etc/penv.conf ]; then \
			${INSTALL_DATA} ${WRKSRC}/penv.conf.default \
				${PREFIX}/etc/penv.conf; \
		fi
.if !defined(NOPORTDOCS)
		${MKDIR} ${DOCSDIR}/html
		${INSTALL_DATA} ${HTMLDOCS:S,^,${WRKSRC}/doc/html/,} ${DOCSDIR}/html
		${MKDIR} ${DOCSDIR}/html/changes
		${INSTALL_DATA} ${HTMLCDOCS:S,^,${WRKSRC}/doc/html/changes/,} ${DOCSDIR}/html/changes
		${MKDIR} ${DOCSDIR}/txt
		${INSTALL_DATA} ${TXTDOCS:S,^,${WRKSRC}/doc/txt/,} ${DOCSDIR}/txt
.endif

.include <bsd.port.mk>
