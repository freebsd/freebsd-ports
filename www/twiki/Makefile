# Ports collection makefile for:	TWiki
# Date created:			Fri Mar  7 14:36:05 CST 2003
# Whom:				Justin Hawkins <justin@hawkins.id.au>
#
# $FreeBSD$
#

PORTNAME=	twiki
PORTVERSION=	4.2.0
PORTEPOCH=	1
CATEGORIES=	www
MASTER_SITES=	http://twiki.org/p/pub/Codev/Release/ \
		GENTOO/distfiles
DISTNAME=	TWiki-${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	infofarmer@FreeBSD.org
COMMENT=	Flexible, powerful, and easy to use enterprise wiki

RUN_DEPENDS=	\
		p5-Algorithm-Diff>=0:${PORTSDIR}/devel/p5-Algorithm-Diff \
		p5-Error>=0:${PORTSDIR}/lang/p5-Error \
		p5-Text-Diff>=0:${PORTSDIR}/textproc/p5-Text-Diff \
		p5-CGI.pm>=0:${PORTSDIR}/www/p5-CGI.pm \
		p5-CGI-Session>=0:${PORTSDIR}/www/p5-CGI-Session \
		p5-Digest-MD5>=0:${PORTSDIR}/security/p5-Digest-MD5 \
		p5-Digest-SHA1>=0:${PORTSDIR}/security/p5-Digest-SHA1 \
		p5-Locale-Maketext-Lexicon>=0:${PORTSDIR}/devel/p5-Locale-Maketext-Lexicon \
		p5-URI>=0:${PORTSDIR}/net/p5-URI \
		p5-PathTools>=0:${PORTSDIR}/devel/p5-PathTools \
		p5-Data-Dumper>=0:${PORTSDIR}/devel/p5-Data-Dumper \
		p5-MIME-Base64>=0:${PORTSDIR}/converters/p5-MIME-Base64 \
		p5-Archive-Tar>=0:${PORTSDIR}/archivers/p5-Archive-Tar \
		p5-HTML-Parser>=0:${PORTSDIR}/www/p5-HTML-Parser

USE_PERL5=	yes

post-extract:
	@cd ${WRKDIR}/ && ${MKDIR} .t/ && ${MV} * .t/ && ${MV} .t ${WRKSRC}
	@${RM} -rf ${WRKSRC}/lib/CPAN
	@${CAT} ${.CURDIR}/../twiki-*/pkg-plist |\
		${SED} -e 's|%%TWDIR%%|${WRKSRC}|;/^@/d' |\
		${XARGS} ${RM} -f
	@${FIND} ${WRKSRC} -name \*,v | while read f; do\
		[ -e $${f%%,v} ] || ${RM} -f $$f; done
	@${FIND} ${WRKSRC} -type d -empty -delete

post-patch:
	@cd ${WRKSRC}/ &&\
		${REINPLACE_CMD} -i "" -e "s|/home/httpd/twiki|${WWWDIR}|g" \
		lib/TWiki.spec twiki_httpd_conf.txt
	@${FIND} ${WRKSRC} -name \*.orig -delete

.include "${.CURDIR}/bsd.twiki.mk"
.include <bsd.port.mk>
