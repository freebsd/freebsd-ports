# New ports collection makefile for:	demime
# Date Created:				25 April 2001
# Whom:					Pete Fritchman <petef@databits.net>
#
# $FreeBSD$
#

PORTNAME=	demime
PORTVERSION= 	0.99d.1
CATEGORIES=	mail textproc
MASTER_SITES=	http://scifi.squawk.com/
DISTFILES=	${PORTNAME}.stable demime_junkmail.cf

MAINTAINER=	petef@FreeBSD.org

RUN_DEPENDS=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/${PERL_ARCH}/MIME/Base64.pm:${PORTSDIR}/converters/p5-MIME-Base64 \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/Bundle/LWP.pm:${PORTSDIR}/www/p5-libwww \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/HTML/FormatText.pm:${PORTSDIR}/textproc/p5-HTML-Format \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/HTML/Element.pm:${PORTSDIR}/www/p5-HTML-Tree \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/HTML/Tagset.pm:${PORTSDIR}/www/p5-HTML-Tagset

NO_BUILD=	yes

USE_PERL5=	yes
POD2MAN?=	pod2man
MAN1=		demime.1

do-extract:
	@${MKDIR} ${WRKSRC}
	@${CP} ${DISTDIR}/demime.stable ${WRKSRC}/demime

post-patch:
	@${PERL} -pi -e 's!/usr/lib/majordomo/demime_junkmail.cf!${PREFIX}/etc/demime_junkmail.cf!g' ${WRKSRC}/demime

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/demime ${PREFIX}/bin/demime
	${INSTALL_DATA} ${DISTDIR}/demime_junkmail.cf ${PREFIX}/etc
	${POD2MAN} ${WRKSRC}/demime > ${PREFIX}/man/man1/demime.1

.include <bsd.port.mk>
