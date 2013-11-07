# Created by: Sergey Skvortsov <skv@protey.ru>
# $FreeBSD$

PORTNAME=	XML-DBMS
PORTVERSION=	1.03
CATEGORIES=	textproc databases perl5
MASTER_SITES=	ftp://ftp.rpbourret.com/
PKGNAMEPREFIX=	p5-
DISTNAME=	perl-xml-dbms-1.03
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Perl port of Java package XML-DBMS v1.0

BUILD_DEPENDS=	p5-libxml>=0:${PORTSDIR}/textproc/p5-libxml \
		p5-XML-LibXML>=0:${PORTSDIR}/textproc/p5-XML-LibXML \
		p5-TimeDate>=0:${PORTSDIR}/devel/p5-TimeDate \
		p5-DBI>=0:${PORTSDIR}/databases/p5-DBI
RUN_DEPENDS:=	${BUILD_DEPENDS}

WRKSRC=		${WRKDIR}/${PORTNAME}
USES=		perl5
USE_PERL5=	configure
USE_DOS2UNIX=	yes

post-install:
.ifndef(NOPORTDOCS)
	@${ECHO_MSG} "===>   Installing examples for ${PKGNAME}"
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/samples/*.* ${STAGEDIR}${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
