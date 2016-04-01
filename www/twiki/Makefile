# Created by: Justin Hawkins <justin@hawkins.id.au>
# $FreeBSD$

PORTNAME=	twiki
PORTVERSION=	6.0.2
PORTEPOCH=	1
CATEGORIES=	www
MASTER_SITES=	SF/${PORTNAME}/TWiki%20for%20all%20Platforms/${DISTNAME} \
		http://twiki.org/p/pub/Codev/Release/
DISTNAME=	TWiki-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Flexible, powerful, and easy to use enterprise wiki

RUN_DEPENDS=	\
		p5-Archive-Zip>=0:archivers/p5-Archive-Zip \
		p5-Algorithm-Diff>=0:devel/p5-Algorithm-Diff \
		p5-Error>=0:lang/p5-Error \
		p5-Text-Diff>=0:textproc/p5-Text-Diff \
		p5-CGI-Session>=0:www/p5-CGI-Session \
		p5-Digest-SHA1>=0:security/p5-Digest-SHA1 \
		p5-Locale-Maketext-Lexicon>=0:devel/p5-Locale-Maketext-Lexicon \
		p5-URI>=0:net/p5-URI \
		p5-Archive-Tar>=0:archivers/p5-Archive-Tar \
		p5-HTML-Parser>=0:www/p5-HTML-Parser \
		p5-libwww>=0:www/p5-libwww \
		twiki-TWikiUserMappingContrib>=0:www/twiki-TWikiUserMappingContrib

USES=		perl5 tar:tgz
WRKSRC=	${WRKDIR}/twiki

USES+=		cpe

post-extract:
	@${RM} -rf ${WRKSRC}/lib/CPAN
	@${CAT} ${.CURDIR}/../twiki-*/pkg-plist |\
		${SED} -e 's|%%TWDIR%%|${WRKSRC}|;/^@/d' |\
		${XARGS} ${RM} -f
	@${FIND} ${WRKSRC} -name \*,v | while read f; do\
		[ -e $${f%%,v} ] || ${RM} -f $$f; done
	@${FIND} ${WRKSRC} -type d -empty -delete

post-patch:
	${SED} -i "" -e "s|/home/httpd/twiki|${WWWDIR}|g" \
		${WRKSRC}/lib/TWiki.spec \
		${WRKSRC}/misc/twiki_httpd_conf.txt
	${FIND} ${WRKSRC} -name \*.orig -delete

.include "${.CURDIR}/bsd.twiki.mk"
.include <bsd.port.mk>
