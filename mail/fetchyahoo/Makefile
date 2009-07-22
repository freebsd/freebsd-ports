# New ports collection makefile for:	fetchyahoo
# Date created:				2003-09-27
# Whom:					trevor
#
# $FreeBSD$
#

PORTNAME=	fetchyahoo
PORTVERSION=	2.13.6
CATEGORIES=	mail
MASTER_SITES=	http://fetchyahoo.twizzler.org/

MAINTAINER=	chalpin@cs.wisc.edu
COMMENT=	Download e-mail from a Yahoo account to a Berkeley mailbox

RUN_DEPENDS=	\
	${SITE_PERL}/${PERL_ARCH}/MIME/Base64.pm:${PORTSDIR}/converters/p5-MIME-Base64 \
	${SITE_PERL}/IO/Lines.pm:${PORTSDIR}/devel/p5-IO-stringy \
	${SITE_PERL}/MIME/Body.pm:${PORTSDIR}/mail/p5-MIME-Tools \
	${SITE_PERL}/Mail/Address.pm:${PORTSDIR}/mail/p5-Mail-Tools \
	${SITE_PERL}/URI.pm:${PORTSDIR}/net/p5-URI \
	${SITE_PERL}/${PERL_ARCH}/Crypt/SSLeay.pm:${PORTSDIR}/security/p5-Crypt-SSLeay \
	${SITE_PERL}/${PERL_ARCH}/HTML/Filter.pm:${PORTSDIR}/www/p5-HTML-Parser \
	${SITE_PERL}/HTTP/Request/Common.pm:${PORTSDIR}/www/p5-libwww \
	${SITE_PERL}/${PERL_ARCH}/Term/ReadKey.pm:${PORTSDIR}/devel/p5-Term-ReadKey

MAN1=		fetchyahoo.1
PLIST_DIRS=	share/examples/fetchyahoo
PLIST_FILES=	bin/fetchyahoo share/examples/fetchyahoo/fetchyahoorc
PORTDOCS=	COPYING ChangeLog Credits INSTALL TODO index.html
NO_BUILD=	yes
USE_PERL5=	yes

do-install:
	@${INSTALL_SCRIPT} ${WRKSRC}/fetchyahoo ${PREFIX}/bin
	@${INSTALL_MAN} ${WRKSRC}/${MAN1} ${MANPREFIX}/man/man1
	@${MKDIR} ${EXAMPLESDIR}
	@${INSTALL_DATA} ${WRKSRC}/fetchyahoorc ${EXAMPLESDIR}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for ii in ${PORTDOCS}
	@${INSTALL_DATA} ${WRKSRC}/${ii} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
