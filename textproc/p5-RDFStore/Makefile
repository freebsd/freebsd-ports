# Created by: Sergey Skvortsov <skv@protey.ru>
# $FreeBSD$

PORTNAME=	RDFStore
PORTVERSION=	0.51
PORTREVISION=	1
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:AREGGIORI
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl API for RDF Storage

BUILD_DEPENDS=	p5-XML-Parser>=0:${PORTSDIR}/textproc/p5-XML-Parser \
		p5-URI>=0:${PORTSDIR}/net/p5-URI \
		p5-DBI>=0:${PORTSDIR}/databases/p5-DBI
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_BDB=	yes
USE_PERL5=	configure

pre-configure:
	@${ECHO} "INCLUDE=${BDB_INCLUDE_DIR}" > ${WRKSRC}/arch_conf.in
	@${ECHO} "LIB=${BDB_LIB_DIR}" >> ${WRKSRC}/arch_conf.in
	@${ECHO} "DBNAME=-l${BDB_LIB_NAME}" >> ${WRKSRC}/arch_conf.in

.include <bsd.port.mk>
