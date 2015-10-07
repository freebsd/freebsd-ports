# Created by: simond@irrelevant.org
# $FreeBSD$

PORTNAME=	EBook-Tools
PORTVERSION=	0.5.4
DISTVERSIONPREFIX=	v
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	junovitch@FreeBSD.org
COMMENT=	Object class for manipulating and generating E-books

LICENSE=	GPLv2

BUILD_DEPENDS=	p5-Archive-Zip>=0:${PORTSDIR}/archivers/p5-Archive-Zip \
		p5-Data-UUID>=0:${PORTSDIR}/devel/p5-Data-UUID \
		p5-Config-IniFiles>=0:${PORTSDIR}/devel/p5-Config-IniFiles \
		p5-Date-Manip>=0:${PORTSDIR}/devel/p5-Date-Manip \
		p5-DBI>=0:${PORTSDIR}/databases/p5-DBI \
		p5-DBD-SQLite>=0:${PORTSDIR}/databases/p5-DBD-SQLite \
		p5-Encode-Detect>=0:${PORTSDIR}/converters/p5-Encode-Detect \
		p5-File-MimeInfo>=0:${PORTSDIR}/devel/p5-File-MimeInfo \
		p5-HTML-Parser>=0:${PORTSDIR}/www/p5-HTML-Parser \
		p5-Lingua-EN-NameParse>=0:${PORTSDIR}/textproc/p5-Lingua-EN-NameParse \
		p5-LWP-Protocol-https>=0:${PORTSDIR}/www/p5-LWP-Protocol-https \
		p5-Mojolicious>=0:${PORTSDIR}/www/p5-Mojolicious \
		p5-Tie-IxHash>=0:${PORTSDIR}/devel/p5-Tie-IxHash \
		p5-XML-Twig>=0:${PORTSDIR}/textproc/p5-XML-Twig \
		p5-File-Slurp>=0:${PORTSDIR}/devel/p5-File-Slurp \
		p5-File-Which>=0:${PORTSDIR}/sysutils/p5-File-Which \
		p5-Palm>=0:${PORTSDIR}/palm/p5-Palm \
		p5-Image-Size>=0:${PORTSDIR}/graphics/p5-Image-Size \
		p5-String-CRC32>=0:${PORTSDIR}/devel/p5-String-CRC32 \
		txt2html>=0:${PORTSDIR}/textproc/txt2html \
		p5-Bit-Vector>=0:${PORTSDIR}/math/p5-Bit-Vector \
		p5-List-MoreUtils>=0:${PORTSDIR}/lang/p5-List-MoreUtils
RUN_DEPENDS:=	${BUILD_DEPENDS}
RUN_DEPENDS+=	${LOCALBASE}/bin/tidy5:${PORTSDIR}/www/tidy-html5

USES=		perl5
USE_PERL5=	modbuild
NO_ARCH=	yes

.include <bsd.port.mk>
