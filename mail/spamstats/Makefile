# Created by: Yen-Ming Lee <leeym@FreeBSD.org>
# $FreeBSD$

PORTNAME=	spamstats
PORTVERSION=	0.6c
PORTREVISION=	2
CATEGORIES=	mail
#MASTER_SITES=	http://www.inl.fr/download/
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	leeym

MAINTAINER=	leeym@FreeBSD.org
COMMENT=	A tool to generate statistics for spamd of Mail::SpamAssassin

RUN_DEPENDS=	p5-Date-Manip>=0:${PORTSDIR}/devel/p5-Date-Manip \
		p5-Compress-Bzip2>=2.08:${PORTSDIR}/archivers/p5-Compress-Bzip2

USE_PERL5=	yes
NO_BUILD=	yes
PORTDOCS=	QUICK README copyright
PLIST_FILES=	bin/spamstats.pl
USES=		shebangfix
SHEBANG_FILES=	${PORTNAME}${PORTVERSION}.pl

post-patch:
	@${REINPLACE_CMD} -i '' -e 's|mail.log|maillog|g' \
		${WRKSRC}/${PORTNAME}${PORTVERSION}.pl

.include <bsd.port.options.mk>

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME}${PORTVERSION}.pl ${PREFIX}/bin/${PORTNAME}.pl
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
