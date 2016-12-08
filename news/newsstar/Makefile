# Created by: Andrey Slusar <anray@FreeBSD.org>
# $FreeBSD$

PORTNAME=	newsstar
PORTVERSION=	1.5.6
PORTREVISION=	2
CATEGORIES=	news
MASTER_SITES=	SF

MAINTAINER=	mandree@FreeBSD.org
COMMENT=	Transfer news between a local NNTP server (INN, sn, s-news)

LICENSE=	GPLv3

LIB_DEPENDS=	libgdbm.so:databases/gdbm
BUILD_DEPENDS=	xmlto:textproc/xmlto \
		${LOCALBASE}/share/xml/docbook/4.5/docbookx.dtd:textproc/docbook-xml

GNU_CONFIGURE=	yes
USES=		iconv perl5 shebangfix
SHEBANG_FILES=	newsstar.in

OPTIONS_DEFINE=		SSL DOCS EXAMPLES
OPTIONS_DEFAULT=	SSL

CONFIGURE_ARGS+=--disable-chown \
		--with-conf-dir=${PREFIX}/etc/newsstar \
		--with-rc-dir=/var/spool/newsstar/lib \
		--with-incoming-dir=/var/spool/newsstar/incoming

CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib ${ICONV_LIB}

.include <bsd.port.options.mk>

.if ! ${PORT_OPTIONS:MDOCS}
INSTALL_TARGET=	install-am
.endif

.if ${PORT_OPTIONS:MSSL}
USE_OPENSSL=	yes
.else
CONFIGURE_ARGS+=--disable-ssl
.endif

.include <bsd.port.pre.mk>

.if exists(/var/spool/s-news)
CONFIGURE_ARGS+=--with-spool-dir=/var/spool/s-news \
		--with-snews-outgoing-dir=${LOCALBASE}/etc/s-news/suck
.endif

.if exists(${LOCALBASE}/sbin/snntpd)
CONFIGURE_ARGS+=--with-sn-spool-dir=/var/spool/news \
		--with-sn-articles-dir=/var/spool/news \
		--with-outgoing-dir=/var/spool/news/.outgoing
.endif

.if exists(${LOCALBASE}/news/bin/innconfval)
CONFIGURE_ARGS+=--with-inn-path=${LOCALBASE}/news/bin
.endif

DOCS=		AUTHORS INSTALL NEWS README TODO docs/QuickStart docs/manual.txt \
		docs/index.html docs/ar01s02.html docs/ar01s03.html docs/ar01s04.html \
		docs/ar01s05.html docs/ar01s06.html docs/ar01s07.html docs/ar01s08.html \
		docs/ar01s09.html docs/ar01s10.html docs/ar01s11.html docs/ar01s12.html \
		docs/news.html

EX_CONFIGS=	cf.server.sample curses.cf.sample filter.pl.sample main.cf.sample \
		master.ignore.sample master.score.sample newsrc.sample

post-patch:
	${REINPLACE_CMD} -e 's|/usr/share/sgml/docbook/dtd/xml|${LOCALBASE}/share/xml/docbook|' ${WRKSRC}/docs/manual.xml
	${REINPLACE_CMD} -e 's|/usr/share/sgml/docbook/dtd/xml|${LOCALBASE}/share/xml/docbook|' ${WRKSRC}/docs/news.xml
	${REINPLACE_CMD} -e 's|install-data-local: install-docs|install-data-local:|' ${WRKSRC}/Makefile.in

post-install:
	${MAKE} -C ${WRKSRC}/src install DESTDIR=${STAGEDIR}
	${MAKE} -C ${WRKSRC}/docs install-man DESTDIR=${STAGEDIR}
	${MKDIR} ${STAGEDIR}/var/spool/newsstar

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
.for i in ${EX_CONFIGS}
	${INSTALL_DATA} ${WRKSRC}/sample_config/${i} ${STAGEDIR}${EXAMPLESDIR}
.endfor

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for i in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${i} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.post.mk>
