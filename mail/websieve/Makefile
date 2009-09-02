# New ports collection makefile for:	websieve
# Date created:				25 Apr 2003
# Whom:				Oliver Eikemeier <eikemeier@fillmore-labs.com>
#
# $FreeBSD$
#

PORTNAME=	websieve
PORTVERSION=	0.63.a
CATEGORIES=	mail
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/063a
DISTNAME?=	${PORTNAME}-${DISTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Web based Cyrus IMAP user admin client

DISTVERSION=	063a

USE_PERL5_RUN=	yes

NO_BUILD=	yes

# Oh for the ability to do radio buttons.  In this case, just use the
# highest select version number.  If no Cyrus IMAPd versions are
# selected, use some generic IMAP modules

OPTIONS=	CYRUS_IMAPD_21	"With Cyrus IMAPd version 2.1.x" off \
		CYRUS_IMAPD_22	"With Cyrus IMAPd version 2.2.x" off \
		CYRUS_IMAPD_23	"With Cyrus IMAPd version 2.3.x" on

.include <bsd.port.pre.mk>

CYRUS_IMAP_PM=	${SITE_PERL}/${PERL_ARCH}/Cyrus/IMAP/Admin.pm

.if defined(WITH_CYRUS_IMAPD_23)
RUN_DEPENDS+=	${CYRUS_IMAP_PM}:${PORTSDIR}/mail/cyrus-imapd23
FUNCLIB_PL=	funclib.cyrus
.elif defined(WITH_CYRUS_IMAPD_22)
RUN_DEPENDS+=	${CYRUS_IMAP_PM}:${PORTSDIR}/mail/cyrus-imapd22
FUNCLIB_PL=	funclib.cyrus
.elif defined(WITH_CYRUS_IMAPD_21)
RUN_DEPENDS+=	${CYRUS_IMAP_PM}:${PORTSDIR}/mail/cyrus-imapd2
FUNCLIB_PL=	funclib.cyrus
.else
RUN_DEPENDS+=	${SITE_PERL}/IMAP/Admin.pm:${PORTSDIR}/mail/p5-IMAP-Admin \
		${SITE_PERL}/IMAP/Sieve.pm:${PORTSDIR}/mail/p5-IMAP-Sieve
FUNCLIB_PL=	funclib.pl
.endif

SUB_FILES=	pkg-message

post-configure:
	@${REINPLACE_CMD} -e "s,require[ 	]*'\./\([^']*\)',require '${PREFIX}/etc/websieve/\1'," \
		${WRKSRC}/websieve.pl

do-install:
	@${MKDIR} ${WWWDIR}
	@${INSTALL_SCRIPT} ${WRKSRC}/websieve.pl ${WWWDIR}/websieve.pl
	@${MKDIR} ${PREFIX}/etc/websieve
	@${INSTALL_DATA} ${WRKSRC}/websieve.conf ${PREFIX}/etc/websieve/websieve.conf.sample
	@${INSTALL_DATA} ${WRKSRC}/${FUNCLIB_PL} ${PREFIX}/etc/websieve/funclib.pl

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
