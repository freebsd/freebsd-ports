# $FreeBSD$

PORTNAME=	Rex
PORTVERSION=	1.6.0
CATEGORIES=	sysutils perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:JFRIED
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Perl framework for automation and systems administration

LICENSE=	APACHE20

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	\
	p5-Devel-Caller>=0:devel/p5-Devel-Caller \
	p5-HTTP-Message>=0:www/p5-HTTP-Message \
	p5-Hash-Merge>=0:textproc/p5-Hash-Merge \
	p5-IO-String>=0:devel/p5-IO-String \
	p5-JSON-XS>=0:converters/p5-JSON-XS \
	p5-libwww>=0:www/p5-libwww \
	p5-List-MoreUtils>=0:lang/p5-List-MoreUtils \
	p5-Sort-Naturally>=0:textproc/p5-Sort-Naturally \
	p5-Term-ReadKey>=0:devel/p5-Term-ReadKey \
	p5-Text-Glob>=0:textproc/p5-Text-Glob \
	p5-URI>0:net/p5-URI \
	p5-XML-Simple>=0:textproc/p5-XML-Simple \
	p5-YAML>=0:textproc/p5-YAML \
	p5-Parallel-ForkManager>=0:devel/p5-Parallel-ForkManager \
	p5-Expect>=0:lang/p5-Expect \
	p5-Digest-HMAC>=0:security/p5-Digest-HMAC \
	p5-HTTP-Date>=0:www/p5-HTTP-Date \
	p5-XML-LibXML>=0:textproc/p5-XML-LibXML \
	p5-Net-SSH2>=0:net/p5-Net-SSH2 \
	p5-Net-OpenSSH>=0:net/p5-Net-OpenSSH \
	p5-Net-SFTP-Foreign>=0:net/p5-Net-SFTP-Foreign


USES=		perl5 shebangfix
USE_PERL5=	configure
NO_ARCH=	yes

SHEBANG_FILES=	lib/Rex/Commands/templates/append_if_no_such_line.tpl.pl

.include <bsd.port.mk>
