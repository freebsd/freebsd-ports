# Created by: trevor
# $FreeBSD$

PORTNAME=	fetchyahoo
PORTVERSION=	2.13.9
CATEGORIES=	mail
MASTER_SITES=	http://fetchyahoo.twizzler.org/

MAINTAINER=	chalpin@cs.wisc.edu
COMMENT=	Download e-mail from a Yahoo account to a Berkeley mailbox

RUN_DEPENDS=	\
	p5-IO-stringy>=0:${PORTSDIR}/devel/p5-IO-stringy \
	p5-MIME-Tools>=0:${PORTSDIR}/mail/p5-MIME-Tools \
	p5-Mail-Tools>=0:${PORTSDIR}/mail/p5-Mail-Tools \
	p5-URI>=0:${PORTSDIR}/net/p5-URI \
	p5-Crypt-SSLeay>=0:${PORTSDIR}/security/p5-Crypt-SSLeay \
	p5-HTML-Parser>=0:${PORTSDIR}/www/p5-HTML-Parser \
	p5-libwww>=0:${PORTSDIR}/www/p5-libwww \
	p5-Term-ReadKey>=0:${PORTSDIR}/devel/p5-Term-ReadKey

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
