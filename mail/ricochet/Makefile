# New ports collection makefile for:	ricochet
# Date created:				02 September 2001
# Whom:	      				Yen-Ming Lee <leeym@leeym.com>
#
# $FreeBSD$
#

PORTNAME=	ricochet
PORTVERSION=	0.98
PORTREVISION=	2
CATEGORIES=	mail
MASTER_SITES=	http://vipul.net/perl/sources/spamcontrol/ricochet/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An automated agent for tracing and reporting internet junk mail

RUN_DEPENDS=	${SITE_PERL}/Mail/Internet.pm:${PORTSDIR}/mail/p5-Mail-Tools \
		${SITE_PERL}/${PERL_ARCH}/Net/DNS.pm:${PORTSDIR}/dns/p5-Net-DNS \
		${SITE_PERL}/Text/Template.pm:${PORTSDIR}/textproc/p5-Text-Template \
		${SITE_PERL}/Net/XWhois.pm:${PORTSDIR}/net/p5-Net-XWhois \
		${SITE_PERL}/LWP/UserAgent.pm:${PORTSDIR}/www/p5-libwww

NO_BUILD=	yes
PERL_CONFIGURE=	yes
USE_REINPLACE=	yes

do-configure:
.for file in install ricochet
	${REINPLACE_CMD} -e 's,/usr/bin/perl,${PERL},g' ${WRKSRC}/${file}
	${REINPLACE_CMD} -e 's,%%PREFIX%%,${PREFIX},g' ${WRKSRC}/${file}
	${REINPLACE_CMD} -e 's,%%INSTALL_DATA%%,${INSTALL_DATA},g' ${WRKSRC}/${file}
.endfor

do-install:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} ./install

.include <bsd.port.mk>
