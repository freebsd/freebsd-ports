# New ports collection makefile for:	ubh
# Date created:			1 January 2002
# Whom:				John Holland <john@zoner.org>
#
# $FreeBSD$
#

PORTNAME=	ubh
PORTVERSION=	2.1
CATEGORIES=	news graphics
MASTER_SITES=	http://ubh.sourceforge.net/download/

MAINTAINER=	john@zoner.org

RUN_DEPENDS=	\
	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/News/Newsrc.pm:${PORTSDIR}/news/p5-News-Newsrc \
	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/Net/NNTP.pm:${PORTSDIR}/net/p5-Net \
	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/Mail/Mailer.pm:${PORTSDIR}/mail/p5-Mail-Tools \
	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/IO/Stringy.pm:${PORTSDIR}/devel/p5-IO-stringy \
	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/i386-freebsd/MIME/Base64.pm:${PORTSDIR}/converters/p5-MIME-Base64 \
	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/MIME/Decoder.pm:${PORTSDIR}/mail/p5-MIME-Tools

NO_BUILD=	YES

pre-patch:
	@${MV} ${WRKSRC}/ubh ${WRKSRC}/ubh.old
	@${SED} -e '1,1s:/usr/bin/perl:${PERL5}:' \
		${WRKSRC}/ubh.old > ${WRKSRC}/ubh

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/ubh ${PREFIX}/bin
	${CP} -R ${WRKSRC}/doc ${PREFIX}/share/doc/ubh
	${CP} -R ${WRKSRC}/examples ${PREFIX}/share/ubh

.include <bsd.port.mk>
