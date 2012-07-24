# New ports collection makefile for:	XML::Encoding
# Date created:		15 Oct 2001
# Whom:			Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	XML-Parser-encodings
PORTVERSION=	1.03
CATEGORIES=	russian textproc perl5
PKGNAMEPREFIX=	p5-
DISTFILES=

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Additional Russian encodings for XML::Parser

RUN_DEPENDS=	p5-XML-Parser>=2.40:${PORTSDIR}/textproc/p5-XML-Parser
BUILD_DEPENDS:=	${RUN_DEPENDS} \
		p5-XML-Encoding>=0:${PORTSDIR}/textproc/p5-XML-Encoding \
		${NONEXISTENT}:${PORTSDIR}/converters/iconv:extract \
		${NONEXISTENT}:${PORTSDIR}/converters/iconv-extra:extract

NO_WRKSUBDIR=	YES
USE_PERL5=	YES
RUSSIANENC=	cp1251 cp866 mac-cyrillic

post-extract:
.for ICONVPORT in iconv iconv-extra
	@${LN} -sfh \
	`cd ${PORTSDIR}/converters/${ICONVPORT} && ${MAKE} -V WRKSRC`/ccs \
	${WRKSRC}/${ICONVPORT}
.endfor

do-configure:
	@${CP} ${WRKSRC}/iconv/cp866.txt ${WRKDIR}
	@${CP} ${WRKSRC}/iconv-extra/windows-1251.txt ${WRKDIR}/cp1251.txt
	@${CP} ${WRKSRC}/iconv-extra/mac-cyrillic.txt ${WRKDIR}
	@${PERL} -pi -e 's/\r/\n/gm;' ${WRKDIR}/mac-cyrillic.txt

do-build:
.for ENC in ${RUSSIANENC}
	@${LOCALBASE}/bin/make_encmap ${ENC} ${WRKDIR}/${ENC}.txt | \
	${PERL} -pi -e "s/(?<=^<encmap name='${ENC}')()(?=>)/ expat='yes'/;" \
		>${WRKDIR}/${ENC}.xml
	@${LOCALBASE}/bin/compile_encoding \
		-o ${WRKDIR}/${ENC}.enc ${WRKDIR}/${ENC}.xml
.endfor

do-install:
	${INSTALL_DATA} ${WRKSRC}/*.enc \
		${PREFIX}/${SITE_PERL_REL}/${PERL_ARCH}/XML/Parser/Encodings/

.include <bsd.port.mk>
