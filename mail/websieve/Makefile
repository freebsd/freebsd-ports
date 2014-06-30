# Created by: Oliver Eikemeier <eikemeier@fillmore-labs.com>
# $FreeBSD$

PORTNAME=	websieve
PORTVERSION=	0.63.a
PORTREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/063a
DISTNAME?=	${PORTNAME}-${DISTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Web based Cyrus IMAP user admin client

DISTVERSION=	063a

USES=		perl5
USE_PERL5=	run

NO_BUILD=	yes

# Oh for the ability to do radio buttons.  In this case, just use the
# highest select version number.  If no Cyrus IMAPd versions are
# selected, use some generic IMAP modules

OPTIONS_DEFINE=	CYRUS_IMAPD_23 CYRUS_IMAPD_24
OPTIONS_DEFAULT=	CYRUS_IMAPD_23

CYRUS_IMAPD_23_DESC=	With Cyrus IMAPd version 2.3.x
CYRUS_IMAPD_24_DESC=	With Cyrus IMAPd version 2.4.x

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MCYRUS_IMAPD_24}
RUN_DEPENDS+=	cyradm:${PORTSDIR}/mail/cyrus-imapd24
FUNCLIB_PL=	funclib.cyrus
.elif ${PORT_OPTIONS:MCYRUS_IMAPD_23}
RUN_DEPENDS+=	cyradm:${PORTSDIR}/mail/cyrus-imapd23
FUNCLIB_PL=	funclib.cyrus
.else
RUN_DEPENDS+=	p5-IMAP-Admin:${PORTSDIR}/mail/p5-IMAP-Admin \
		p5-IMAP-Sieve:${PORTSDIR}/mail/p5-IMAP-Sieve
FUNCLIB_PL=	funclib.pl
.endif

SUB_FILES=	pkg-message

post-configure:
	@${REINPLACE_CMD} -e "s,require[ 	]*'\./\([^']*\)',require '${PREFIX}/etc/websieve/\1'," \
		${WRKSRC}/websieve.pl

do-install:
	@${MKDIR} ${STAGEDIR}${WWWDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/websieve.pl ${STAGEDIR}${WWWDIR}/websieve.pl
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/websieve
	${INSTALL_DATA} ${WRKSRC}/websieve.conf ${STAGEDIR}${PREFIX}/etc/websieve/websieve.conf.sample
	${INSTALL_DATA} ${WRKSRC}/${FUNCLIB_PL} ${STAGEDIR}${PREFIX}/etc/websieve/funclib.pl

.include <bsd.port.mk>
