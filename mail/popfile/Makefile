# Created by: matusita@FreeBSD.org
# $FreeBSD$

PORTNAME=	popfile
PORTVERSION=	1.1.3
CATEGORIES=	mail
MASTER_SITES=	http://getpopfile.org/downloads/%SUBDIR%/
MASTER_SITE_SUBDIR=	. archive
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Automatic mail classification tool, acts as a POP3 proxy

LICENSE=	GPLv2

RUN_DEPENDS=	p5-DBD-SQLite>=0:${PORTSDIR}/databases/p5-DBD-SQLite \
		p5-TimeDate>=0:${PORTSDIR}/devel/p5-TimeDate \
		p5-HTML-Tagset>=0:${PORTSDIR}/www/p5-HTML-Tagset \
		p5-HTML-Template>=0:${PORTSDIR}/www/p5-HTML-Template

OPTIONS_DEFINE=	SSL XMLRPC UPGRADE_FROM_0_20 KAKASI MECABU
SSL_DESC=	\
	Depend SSL libraries/modules to use SSL connection to the servers
XMLRPC_DESC=	\
	Depend SOAP libraries to use POPFile as XMLRPC server
UPGRADE_FROM_0_20_DESC=	\
	Depend BerkeleyDB libraries to upgrade old POPFile corpus
KAKASI_DESC=	\
	Depend Kakasi library to handle Japanese text
MECABU_DESC=	\
	Depend MeCab library to handle Japanese text

NO_WRKSUBDIR=	yes
NO_BUILD=	yes

USES=		perl5 zip
USE_PERL5=	run

PLIST_SUB=	VERSION="${PORTVERSION}"

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MSSL}
# POPFile works with IO::Socket::SSL version 1.07 (and not 0.97/0.99).
RUN_DEPENDS+=  p5-IO-Socket-SSL>=1.07:${PORTSDIR}/security/p5-IO-Socket-SSL
.endif

.if ${PORT_OPTIONS:MXMLRPC}
RUN_DEPENDS+=  p5-SOAP-Lite>=0:${PORTSDIR}/net/p5-SOAP-Lite
.endif

#.if ${PORT_OPTIONS:MSOCKS}
# XXX: IO::Socket::Socks should be listed here but no ports yet. For those
# interested, check http://search.cpan.org/~reatmon/IO-Socket-Socks-0.1/.
#.endif

.if ${PORT_OPTIONS:MUPGRADE_FROM_0_20}
RUN_DEPENDS+=	p5-BerkeleyDB>=0:${PORTSDIR}/databases/p5-BerkeleyDB
.endif

.if ${PORT_OPTIONS:MKAKASI}
RUN_DEPENDS+=	p5-Text-Kakasi>=0:${PORTSDIR}/japanese/p5-Text-Kakasi
.endif

.if ${PORT_OPTIONS:MMECAB}
RUN_DEPENDS+=	p5-MeCab>=0:${PORTSDIR}/japanese/p5-MeCab
.endif

post-patch:
	@${REINPLACE_CMD} -e \
		's|^#!/usr/bin/perl$$|#!${PERL}|' ${WRKSRC}/popfile.pl
	@${SED} 's|%%DATADIR%%|${DATADIR}|' \
		< ${FILESDIR}/popfile.sh > ${WRKDIR}/popfile.sh

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/popfile.sh ${PREFIX}/sbin
	@${MKDIR} ${DATADIR}
	(cd ${WRKSRC} && ${INSTALL_SCRIPT} *.pl ${DATADIR})
	(cd ${WRKSRC} && ${INSTALL_DATA} \
		stopwords *.change* *.gif *.ico *.pck *.png ${DATADIR})
.for i in Classifier POPFile Proxy Services UI languages skins
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} ${i} ${DATADIR})
.endfor

.include <bsd.port.mk>
