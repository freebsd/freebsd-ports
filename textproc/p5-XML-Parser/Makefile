# New ports collection makefile for:	XML::Parser
# Date created:		15 Nov 1998
# Whom:			Jun Kuriyama <kuriyama@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	XML-Parser
PORTVERSION=	2.30
PORTREVISION=	1
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN} \
		http://wwwx.netheaven.com/~coopercc/xmlparser/
MASTER_SITE_SUBDIR=	XML
PKGNAMEPREFIX=	p5-
DISTFILES=	${PORTNAME}.${PORTVERSION}.tar.gz

MAINTAINER=	kuriyama@FreeBSD.org

LIB_DEPENDS=	expat.2:${PORTSDIR}/textproc/expat2

PERL_CONFIGURE=	yes
CONFIGURE_ARGS=	EXPATLIBPATH=${LOCALBASE}/lib EXPATINCPATH=${LOCALBASE}/include

MAN3=		XML::Parser.3 XML::Parser::Expat.3
MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}
PLIST_SUB=	EUCJP=${EUCJP} SJIS=${SJIS}

# XMLPARSER_EUCJP=	x-euc-jp-(jisx0221|unicode)
# XMLPARSER_SJIS=	x-sjis-(cp932|jdk117|jisx0221|unicode)
CONV_ENC=	perl -e '$$e=shift @ARGV; undef $$/; $$_=<>; substr($$_,4,40)=pack("a40","$$e"); print'
.if !defined(XMLPARSER_EUCJP)
EUCJP=		"@comment "
.endif
.if !defined(XMLPARSER_SJIS)
SJIS=		"@comment "
.endif

post-patch:
.if defined(XMLPARSER_EUCJP)
	@cd ${WRKSRC}/Parser/Encodings; \
		${CONV_ENC} euc-jp ${XMLPARSER_EUCJP}.enc > euc-jp.enc
	@${ECHO} Parser/Encodings/euc-jp.enc >> ${WRKSRC}/MANIFEST
.endif
.if defined(XMLPARSER_SJIS)
	@cd ${WRKSRC}/Parser/Encodings; \
		${CONV_ENC} shift_jis ${XMLPARSER_SJIS}.enc > shift_jis.enc
	@${ECHO} Parser/Encodings/Shift_JIS.enc >> ${WRKSRC}/MANIFEST
.endif

post-configure:
	@${PERL} -i -pe 's/^(CC = ).*/$$1 ${CC}/;' \
		-e 's/^(CCFLAGS = ).*/$$1 ${CFLAGS}/' ${WRKSRC}/Expat/Makefile

.include <bsd.port.mk>
