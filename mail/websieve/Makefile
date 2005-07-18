# New ports collection makefile for:	websieve
# Date created:				25 Apr 2003
# Whom:				Oliver Eikemeier <eikemeier@fillmore-labs.com>
#
# $FreeBSD$
#

PORTNAME=	websieve
PORTVERSION=	0.63.a
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE_EXTENDED}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME?=	${PORTNAME}-${DISTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Web based Cyrus IMAP user admin client

DISTVERSION=	063a

.include "options"

.if defined(WITH_CYRUS_IMAPD_VER)
.if ${WITH_CYRUS_IMAPD_VER} == 22
RUN_DEPENDS=	${CYRUS_IMAP_PM}:${PORTSDIR}/mail/cyrus-imapd22
.elif ${WITH_CYRUS_IMAPD_VER} == 21
RUN_DEPENDS=	${CYRUS_IMAP_PM}:${PORTSDIR}/mail/cyrus-imapd2
.else
.error WITH_CYRUS_IMAPD_VER must be 22 or 21
.endif
.else
RUN_DEPENDS=	${SITE_PERL}/IMAP/Admin.pm:${PORTSDIR}/mail/p5-IMAP-Admin \
		${SITE_PERL}/IMAP/Sieve.pm:${PORTSDIR}/mail/p5-IMAP-Sieve
.endif
RUN_DEPENDS+=	${LOCALBASE}/www/cgi-bin:${PORTSDIR}/${APACHE_PORT}

PKGMESSAGE=	${WRKDIR}/pkg-message

USE_REINPLACE=	yes
USE_PERL5_RUN=	yes

NO_BUILD=	yes

CYRUS_IMAP_PM=	${SITE_PERL}/${PERL_ARCH}/Cyrus/IMAP/Admin.pm

.if defined(WITH_CYRUS_IMAPD_VER)
FUNCLIB_PL=	funclib.cyrus
.else
FUNCLIB_PL=	funclib.pl
.endif

post-configure:
	@${REINPLACE_CMD} -e "s,require[ 	]*'\./\([^']*\)',require '${PREFIX}/etc/websieve/\1'," \
		${WRKSRC}/websieve.pl

do-install:
	@${INSTALL_SCRIPT} ${WRKSRC}/websieve.pl ${PREFIX}/www/cgi-bin
	@${MKDIR} ${PREFIX}/etc/websieve
	@${INSTALL_DATA} ${WRKSRC}/websieve.conf ${PREFIX}/etc/websieve/websieve.conf.sample
	@${INSTALL_DATA} ${WRKSRC}/${FUNCLIB_PL} ${PREFIX}/etc/websieve/funclib.pl
	@${SED} 's,%%PREFIX%%,${PREFIX},g' ${.CURDIR}/pkg-message > ${PKGMESSAGE}

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
