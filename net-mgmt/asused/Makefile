# New ports collection makefile for:	asused
# Date created:		2006-07-19
# Whom:			Babak Farrokhi <babak@farrokhi.net>
#
# $FreeBSD$
#

PORTNAME=	asused
PORTVERSION=	3.72
CATEGORIES=	net-mgmt perl5
MASTER_SITES=	ftp://ftp.ripe.net/tools/ \
		http://ftp.belnet.be/pub/mirror/ftp.ripe.net/ripe/tools/
DISTNAME=	${PORTNAME}-${PORTVERSION}_whois_new_query_fix

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Command-line tool to run a check on the usage of the RIPE Whois DB

DEPRECATED=     Upstream disapear and distfile is no more available
EXPIRATION_DATE=        2011-05-01

PERL_CONFIGURE=	yes

MAN1=		asused.1
MAN3=		ArinWhois.3 NCC::CountryCode.3 NCC::RipeDelegations.3 \
		Net::RIPEWhois::in.3 Reg::Asused.3 RipeWhois.3 Whois.3 asused.3

post-patch:
	@${REINPLACE_CMD} -e 's|asused\.conf|${PREFIX}/etc/asused\.conf|g' \
		${WRKSRC}/asused.PL

post-install:
	@${INSTALL_DATA} ${WRKSRC}/asused.conf ${PREFIX}/etc/asused.conf.dist
.if !exists(${PREFIX}/etc/asused.conf)
	@${INSTALL_DATA} ${WRKSRC}/asused.conf ${PREFIX}/etc/asused.conf
.endif

.include <bsd.port.mk>
