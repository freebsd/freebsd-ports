# New ports collection makefile for:	ricochet
# Date created:				02 September 2001
# Whom:	      				Yen-Ming Lee <leeym@leeym.com>
#
# $FreeBSD$
#

PORTNAME=	ricochet
PORTVERSION=	0.97
PORTREVISION=   6
CATEGORIES=	mail
MASTER_SITES=	http://vipul.net/perl/sources/spamcontrol/ricochet/

MAINTAINER=	leeym@FreeBSD.org

RUN_DEPENDS=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/Mail/Internet.pm:${PORTSDIR}/mail/p5-Mail-Tools \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/Net/DNS.pm:${PORTSDIR}/net/p5-Net-DNS \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/Text/Template.pm:${PORTSDIR}/textproc/p5-Text-Template \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/Net/XWhois.pm:${PORTSDIR}/net/p5-Net-XWhois \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/LWP/UserAgent.pm:${PORTSDIR}/www/p5-libwww

NO_BUILD=	yes

do-configure:
.for file in install ricochet
	${PERL5} -pi -e 's,%%PREFIX%%,${PREFIX},g' ${WRKSRC}/${file}
	${PERL5} -pi -e 's,%%INSTALL_DATA%%,${INSTALL_DATA},g' ${WRKSRC}/${file}
.endfor

do-install:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} ./install

.include <bsd.port.mk>
