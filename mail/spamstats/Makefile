# Created by: Yen-Ming Lee <leeym@FreeBSD.org>
# $FreeBSD$

PORTNAME=	spamstats
PORTVERSION=	0.6c
PORTREVISION=	2
CATEGORIES=	mail
#MASTER_SITES=	http://www.inl.fr/download/
MASTER_SITES=	LOCAL/leeym

MAINTAINER=	leeym@FreeBSD.org
COMMENT=	Tool to generate statistics for spamd of Mail::SpamAssassin

RUN_DEPENDS=	p5-Date-Manip>=0:devel/p5-Date-Manip \
		p5-Compress-Bzip2>=2.08:archivers/p5-Compress-Bzip2

NO_BUILD=	yes
PORTDOCS=	QUICK README copyright
PLIST_FILES=	bin/spamstats.pl
USES=		shebangfix perl5
SHEBANG_FILES=	${PORTNAME}${PORTVERSION}.pl

post-patch:
	@${REINPLACE_CMD} -i '' -e 's|mail.log|maillog|g' \
		${WRKSRC}/${PORTNAME}${PORTVERSION}.pl

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME}${PORTVERSION}.pl \
		${STAGEDIR}${PREFIX}/bin/${PORTNAME}.pl
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
