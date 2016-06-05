# $FreeBSD$

PORTNAME=	wwwstat
PORTVERSION=	2.01
PORTREVISION=	6
CATEGORIES=	www
MASTER_SITES=	ftp://ftp.ics.uci.edu/pub/websoft/wwwstat/ \
		ftp://ftp.gwdg.de/pub/misc/www-stat/websoft/wwwstat/
DISTNAME=	${PORTNAME}-2.0

PATCH_SITES=	${MASTER_SITES}
PATCHFILES=	patch-2.01.txt

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Webserver logfile analysis package

BROKEN=		unfetchable
DEPRECATED=	Broken for more than 6 months
EXPIRATION_DATE=	2016-07-04

LICENSE=	ART10

USE_APACHE_RUN=	22+
USES=		perl5
MAKE_ENV+=	PERL=${PERL}
SUB_FILES=	pkg-message
SUB_LIST=	SITE_PERL=${PREFIX}/${SITE_PERL_REL}

BIN_FILES=	monthly oldlog2new splitlog wwwerrs wwwstat
SPERL_FILES=	domains.pl splitlog.rc wwwstat.rc
MAN1_FILES=	wwwstat.1 splitlog.1

do-install:
	${INSTALL_SCRIPT} ${BIN_FILES:S|^|${WRKSRC}/|} ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${PREFIX}/${SITE_PERL_REL}
	${INSTALL_DATA} ${SPERL_FILES:S|^|${WRKSRC}/|} ${STAGEDIR}${PREFIX}/${SITE_PERL_REL}
	${INSTALL_MAN} ${MAN1_FILES:S|^|${WRKSRC}/|} ${STAGEDIR}${PREFIX}/man/man1

.include <bsd.port.mk>
