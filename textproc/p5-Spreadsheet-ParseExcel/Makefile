# Created by: Sergey Skvortsov <skv@protey.ru>
# $FreeBSD$

PORTNAME=	Spreadsheet-ParseExcel
PORTVERSION=	0.59
PORTEPOCH=	1
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Get information from Excel file

BUILD_DEPENDS=	p5-OLE-Storage_Lite>=0.19:${PORTSDIR}/devel/p5-OLE-Storage_Lite \
		p5-Crypt-RC4>=0:${PORTSDIR}/security/p5-Crypt-RC4 \
		p5-Digest-Perl-MD5>=0:${PORTSDIR}/security/p5-Digest-Perl-MD5
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

post-install:
.ifndef(NOPORTEXAMPLES)
	@${ECHO_MSG} "===>   Installing examples for ${PKGNAME}"
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/Excel
	${INSTALL_DATA} ${WRKSRC}/sample/README ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/sample/*.pl ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/sample/Excel/* ${STAGEDIR}${EXAMPLESDIR}/Excel
.endif

.include <bsd.port.mk>
