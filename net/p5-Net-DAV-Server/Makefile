# Created by: Gea-Suan Lin <gslin@gslin.org>
# $FreeBSD$

PORTNAME=	Net-DAV-Server
PORTVERSION=	1.30.5
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}-${PORTVERSION:C/\.(.)$/\1/}

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Provide a DAV Server

RUN_DEPENDS=	p5-DBD-SQLite>=0:${PORTSDIR}/databases/p5-DBD-SQLite \
		p5-DBI>=0:${PORTSDIR}/databases/p5-DBI \
		p5-Digest-SHA1>=0:${PORTSDIR}/security/p5-Digest-SHA1 \
		p5-File-Find-Rule-Filesys-Virtual>=0:${PORTSDIR}/devel/p5-File-Find-Rule-Filesys-Virtual \
		p5-File-Slurp>=0:${PORTSDIR}/devel/p5-File-Slurp \
		p5-URI>=0:${PORTSDIR}/net/p5-URI \
		p5-XML-LibXML>=1.62000:${PORTSDIR}/textproc/p5-XML-LibXML \
		p5-libwww>=0:${PORTSDIR}/www/p5-libwww

USES=		perl5
USE_PERL5=	modbuild

.include <bsd.port.mk>
