# New ports collection makefile for:	websieve
# Date created:				25 Apr 2003
# Whom:				Oliver Eikemeier <eikemeier@fillmore-labs.com>
#
# $FreeBSD$
#

PORTNAME=	websieve
PORTVERSION=	0.61
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	eikemeier@fillmore-labs.com
COMMENT=	Web based Cyrus IMAP user admin client

RUN_DEPENDS=	${SITE_PERL}/IMAP/Admin.pm:${PORTSDIR}/mail/p5-IMAP-Admin \
		${SITE_PERL}/IMAP/Sieve.pm:${PORTSDIR}/mail/p5-IMAP-Sieve \
		${SITE_PERL}/CGI/Cache.pm:${PORTSDIR}/www/p5-CGI-Cache
.if defined(WITH_APACHE2)
RUN_DEPENDS+=	${LOCALBASE}/www/cgi-bin:${PORTSDIR}/www/apache2
.else
RUN_DEPENDS+=	${LOCALBASE}/www/cgi-bin:${PORTSDIR}/www/apache13
.endif

WRKSRC=		${WRKDIR}/${PORTNAME}
PKGMESSAGE=	${WRKDIR}/pkg-message

USE_REINPLACE=	yes
USE_PERL5_RUN=	yes

NO_BUILD=	yes

post-configure:
	@${REINPLACE_CMD} -e "s,require[ 	]*'\./\([^']*\)',require '${PREFIX}/etc/websieve/\1'," \
		${WRKSRC}/websieve.pl

do-install:
	@${INSTALL_SCRIPT} ${WRKSRC}/websieve.pl ${PREFIX}/www/cgi-bin
	@${MKDIR} ${PREFIX}/etc/websieve
	@${INSTALL_DATA} ${WRKSRC}/websieve.conf ${PREFIX}/etc/websieve/websieve.conf.sample
	@${INSTALL_DATA} ${WRKSRC}/funclib.pl ${PREFIX}/etc/websieve
	@@${SED} 's,%%PREFIX%%,${PREFIX},g' ${.CURDIR}/pkg-message > ${PKGMESSAGE}

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
