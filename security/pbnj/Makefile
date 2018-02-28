# Created by: Joshua D. Abraham <jabra@ccs.neu.edu>
# $FreeBSD$

PORTNAME=	pbnj
PORTVERSION=	2.04
PORTREVISION=	2
CATEGORIES=	security
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Suite of tools to monitor changes on a network

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	p5-DBD-SQLite>=0:databases/p5-DBD-SQLite \
		p5-File-HomeDir>=0:devel/p5-File-HomeDir \
		p5-File-Which>=0:sysutils/p5-File-Which \
		p5-Nmap-Parser>=0:security/p5-Nmap-Parser \
		p5-Text-CSV_XS>=0:textproc/p5-Text-CSV_XS \
		p5-XML-Twig>=0:textproc/p5-XML-Twig \
		p5-YAML>=0:textproc/p5-YAML
RUN_DEPENDS:=	nmap:security/nmap \
		${BUILD_DEPENDS}

NO_ARCH=	yes
USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
