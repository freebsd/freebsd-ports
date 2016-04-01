# Created by: matusita@FreeBSD.org
# $FreeBSD$

PORTNAME=	popfile
PORTVERSION=	1.1.3
PORTREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	http://getpopfile.org/downloads/%SUBDIR%/
MASTER_SITE_SUBDIR=	. archive
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Automatic mail classification tool, acts as a POP3 proxy

LICENSE=	GPLv2

RUN_DEPENDS=	p5-DBD-SQLite>=0:databases/p5-DBD-SQLite \
		p5-TimeDate>=0:devel/p5-TimeDate \
		p5-HTML-Tagset>=0:www/p5-HTML-Tagset \
		p5-HTML-Template>=0:www/p5-HTML-Template

NO_WRKSUBDIR=	yes
NO_BUILD=	yes
NO_ARCH=	yes

USES=		perl5 shebangfix zip
USE_PERL5=	run
SHEBANG_FILES=	bayes.pl insert.pl \
		pipe.pl popfile.pl

PLIST_SUB=	VERSION="${PORTVERSION}"
SUB_FILES=	popfile.sh

OPTIONS_DEFINE=	SSL XMLRPC UPGRADE_FROM_0_20 KAKASI MECABU

# POPFile works with IO::Socket::SSL version 1.07 (and not 0.97/0.99).
SSL_RUN_DEPENDS=p5-IO-Socket-SSL>=1.07:security/p5-IO-Socket-SSL

XMLRPC_DESC=		POPFile as XMLRPC server
XMLRPC_RUN_DEPENDS=	p5-SOAP-Lite>=0:net/p5-SOAP-Lite

UPGRADE_FROM_0_20_DESC=		Upgrade old POPFile corpus
UPGRADE_FROM_0_20_RUN_DEPENDS=	p5-BerkeleyDB>=0:databases/p5-BerkeleyDB

KAKASI_DESC=		Handle Japanese text via Kakasi library
KAKASI_RUN_DEPENDS=	p5-Text-Kakasi>=0:japanese/p5-Text-Kakasi

MECABU_DESC=		Handle Japanese text via MeCab library
MECABU_RUN_DEPENDS=	p5-MeCab>=0:japanese/p5-MeCab

#.if ${PORT_OPTIONS:MSOCKS}
# XXX: IO::Socket::Socks should be listed here but no ports yet. For those
# interested, check http://search.cpan.org/~reatmon/IO-Socket-Socks-0.1/.
#.endif

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/popfile.sh ${STAGEDIR}${PREFIX}/sbin
	@${MKDIR} ${STAGEDIR}${DATADIR}
	(cd ${WRKSRC} && ${INSTALL_SCRIPT} *.pl ${STAGEDIR}${DATADIR})
	(cd ${WRKSRC} && ${INSTALL_DATA} stopwords *.change* *.gif *.ico \
		*.pck *.png ${STAGEDIR}${DATADIR})
.for i in Classifier POPFile Proxy Services UI languages skins
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} ${i} ${STAGEDIR}${DATADIR})
.endfor

.include <bsd.port.mk>
