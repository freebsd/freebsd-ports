# Created by: Sergey Skvortsov <skv@protey.ru>
# $FreeBSD$

PORTNAME=	XML-Parser-encodings
PORTVERSION=	1.03
PORTREVISION=	1
CATEGORIES=	russian textproc perl5
DISTFILES=

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Additional Russian encodings for XML::Parser

RUN_DEPENDS=	p5-XML-Parser>=2.40:textproc/p5-XML-Parser
BUILD_DEPENDS:=	${RUN_DEPENDS} \
		p5-XML-Encoding>=0:textproc/p5-XML-Encoding \
		${NONEXISTENT}:converters/iconv:extract \
		${NONEXISTENT}:converters/iconv-extra:extract

USES=		perl5
NO_WRKSUBDIR=	YES
RUSSIANENC=	cp1251 cp866 mac-cyrillic

.include <bsd.port.pre.mk>

PKGNAMEPREFIX:=	${PKGNAMEPREFIX}p5-

post-extract:
.for ICONVPORT in iconv iconv-extra
	@${LN} -sfh \
		`cd ${PORTSDIR}/converters/${ICONVPORT} && ${MAKE} -V WRKSRC`/ccs \
		${WRKSRC}/${ICONVPORT}
.endfor

do-configure:
	@${CP} ${WRKSRC}/iconv/cp866.txt ${WRKSRC}
	@${CP} ${WRKSRC}/iconv-extra/windows-1251.txt ${WRKSRC}/cp1251.txt
	@${CP} ${WRKSRC}/iconv-extra/mac-cyrillic.txt ${WRKSRC}
	@${PERL} -pi -e 's/\r/\n/gm;' ${WRKSRC}/mac-cyrillic.txt

do-build:
.for ENC in ${RUSSIANENC}
	@${LOCALBASE}/bin/make_encmap ${ENC} ${WRKSRC}/${ENC}.txt | \
	${PERL} -pi -e "s/(?<=^<encmap name='${ENC}')()(?=>)/ expat='yes'/;" \
		>${WRKSRC}/${ENC}.xml
	@${LOCALBASE}/bin/compile_encoding \
		-o ${WRKSRC}/${ENC}.enc ${WRKSRC}/${ENC}.xml
.endfor

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/XML/Parser/Encodings
	${INSTALL_DATA} ${WRKSRC}/*.enc \
		${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/XML/Parser/Encodings

.include <bsd.port.post.mk>
