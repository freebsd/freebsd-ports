# $FreeBSD$

PORTNAME=	Rex
PORTVERSION=	0.44.6.1
CATEGORIES=	sysutils perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:JFRIED
PKGNAMEPREFIX=	p5-

MAINTAINER=	sam@cassiba.com
COMMENT=	Perl framework for automation and systems administration

LICENSE=	APACHE20

BUILD_DEPENDS=	\
	p5-Net-SSH2>=0:${PORTSDIR}/net/p5-Net-SSH2 \
	p5-Expect>=0:${PORTSDIR}/lang/p5-Expect \
	p5-DBI>=0:${PORTSDIR}/databases/p5-DBI \
	p5-Digest-HMAC>=0:${PORTSDIR}/security/p5-Digest-HMAC \
	p5-HTTP-Date>=0:${PORTSDIR}/www/p5-HTTP-Date \
	p5-JSON-XS>=0:${PORTSDIR}/converters/p5-JSON-XS \
	p5-libwww>=0:${PORTSDIR}/www/p5-libwww \
	p5-String-Escape>=0:${PORTSDIR}/textproc/p5-String-Escape \
	p5-XML-Simple>=0:${PORTSDIR}/textproc/p5-XML-Simple \
	p5-YAML>=0:${PORTSDIR}/textproc/p5-YAML \
	p5-List-MoreUtils>=0:${PORTSDIR}/lang/p5-List-MoreUtils

RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5 shebangfix
USE_PERL5=	configure

SHEBANG_FILES=	lib/Rex/Commands/templates/append_if_no_such_line.tpl.pl

.include <bsd.port.mk>
