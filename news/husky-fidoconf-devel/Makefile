# New ports collection makefile for:	husky-fidoconf-devel
# Date created:				2005-10-26
# Whom:					Oleg Sharoiko <os@rsu.ru>
#
# $FreeBSD$
#

PORTNAME=	fidoconf
DISTVERSION=	1.4-rc4
CATEGORIES=	news mail
DISTNAME=	${PORTNAME}-${DISTVERSION}-src

MAINTAINER=	os@rsu.ru
COMMENT=	Configuration library for Husky Fidosoft Project. Development version

LIB_DEPENDS=	smapi.2:${PORTSDIR}/news/husky-smapi-devel
RUN_DEPENDS=	${LOCALBASE}/etc/fido/huskymak.cfg:${PORTSDIR}/news/husky-base-devel

CONFLICTS=	husky-fidoconf-[0-9]*

INSTALLS_SHLIB=	yes
NO_FILTER_SHLIBS=	yes
INSTALL_TARGET=	install install-man

MAN1=		dumpfcfg.1 fconf2.1 linked.1 linkedto.1 tparser.1
MLINKS=		fconf2.1 fconf2aquaed.1 \
		fconf2.1 fconf2areasbbs.1 \
		fconf2.1 fconf2binkd.1 \
		fconf2.1 fconf2dir.1 \
		fconf2.1 fconf2fidogate.1 \
		fconf2.1 fconf2golded.1 \
		fconf2.1 fconf2msged.1 \
		fconf2.1 fconf2na.pl.1 \
		fconf2.1 fconf2squish.1 \
		fconf2.1 fconf2tornado.1 \
		fconf2.1 fecfg2fconf.1
INFO=		fidoconfig

post-patch:
	@${REINPLACE_CMD} -e 's^/fido/etc/config^${PREFIX}/etc/fido/config^' \
		${WRKSRC}/man/dumpfcfg.1
	@${REINPLACE_CMD} -e 's^/etc/fido/config^${PREFIX}/etc/fido/config^' \
		${WRKSRC}/man/fconf2.1 \
		${WRKSRC}/man/tparser.1

.include <bsd.port.pre.mk>
.include "${.CURDIR}/../../news/husky-base-devel/Makefile.inc"
.include <bsd.port.post.mk>
