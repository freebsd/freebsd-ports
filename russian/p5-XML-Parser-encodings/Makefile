# New ports collection makefile for:	XML::Encoding
# Date created:		15 Oct 2001
# Whom:			Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	XML-Parser-encodings
PORTVERSION=	1.00
CATEGORIES=	russian textproc perl5
PKGNAMEPREFIX=	p5-
DISTFILES=

MAINTAINER=	skv@protey.ru

BUILD_DEPENDS=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/${PERL_ARCH}/XML/Parser.pm:${PORTSDIR}/textproc/p5-XML-Parser \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/XML/Encoding.pm:${PORTSDIR}/textproc/p5-XML-Encoding \
		${NONEXISTENT}:${PORTSDIR}/converters/iconv:extract \
		${NONEXISTENT}:${PORTSDIR}/converters/iconv-extra:extract
RUN_DEPENDS=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/${PERL_ARCH}/XML/Parser.pm:${PORTSDIR}/textproc/p5-XML-Parser

NO_WRKSUBDIR=	YES

ICONVCCSDIR=	${PORTSDIR}/converters/iconv/work/iconv-2.0/ccs
ICONVEXTRACCSDIR=	\
		${PORTSDIR}/converters/iconv-extra/work/iconv-extra-2.0/ccs
RUSSIANENC=	windows-1251 koi8-r cp1251 cp866 mac-cyrillic

do-configure:
.for ENC in koi8-r cp866
	@${CP} ${ICONVCCSDIR}/${ENC}.txt ${WRKDIR}
.endfor
.for ENC in mac-cyrillic windows-1251
	@${CP} ${ICONVEXTRACCSDIR}/${ENC}.txt ${WRKDIR}
.endfor
	@${CP} ${WRKDIR}/windows-1251.txt ${WRKDIR}/cp1251.txt
	@${PERL} -pi -e 's/\r/\n/gm;' ${WRKDIR}/mac-cyrillic.txt

do-build:
.for ENC in ${RUSSIANENC}
	@${PREFIX}/bin/make_encmap ${ENC} ${WRKDIR}/${ENC}.txt | \
	${PERL} -pi -e "s/(?<=^<encmap name='${ENC}')()(?=>)/ expat='yes'/;" \
		>${WRKDIR}/${ENC}.xml
	@${PREFIX}/bin/compile_encoding \
		-o ${WRKDIR}/${ENC}.enc ${WRKDIR}/${ENC}.xml
.endfor

}.encENC}l:

do-install:
.for ENC in ${RUSSIANENC}
	${INSTALL_DATA} ${WRKDIR}/${ENC}.enc \
		${PREFIX}/lib/perl5/site_perl/${PERL_VER}/${PERL_ARCH}/XML/Parser/Encodings/
.endfor

.include <bsd.port.mk>
