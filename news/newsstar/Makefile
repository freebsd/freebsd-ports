# New ports collection makefile for:	newsstar
# Date created:				9 May 2004
# Whom:					Andrey Slusar <vasallia@ukr.net>
#
# $FreeBSD$
#

PORTNAME=	newsstar
PORTVERSION=	1.1.1
CATEGORIES=	news
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	anray@inet.ua
COMMENT=	Transfer news between a local NNTP server (INN or sn)

.if !defined(WITH_SN)
RUN_DEPENDS=	${LOCALBASE}/news/bin/innd:${PORTSDIR}/news/inn
.else
RUN_DEPENDS=	${LOCALBASE}/sbin/snntpd:${PORTSDIR}/news/sn
.endif

.if defined(WITHOUT_SSL)
CONFIGURE_ARGS+=--disable-ssl
.else
USE_OPENSSL=	yes
.endif

.if !defined(WITH_SN)
CONFIGURE_ARGS+=--with-inn-path=${PREFIX}/news/bin
.endif

CONFIGURE_ARGS+=--prefix=${PREFIX} \
		--with-conf-dir=${PREFIX}/etc/newsstar \
		--with-rc-dir=/var/spool/newsstar/lib \
		--with-incoming-dir=/var/spool/newsstar/incoming

CONFIGURE_ENV=  CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"

USE_PERL5=	yes
HAS_CONFIGURE=	yes

MAN1=		newsstar.1
DOCS=		AUTHORS INSTALL NEWS README TODO docs/QuickStart docs/manual.txt \
		docs/index.html docs/ar01s02.html docs/ar01s03.html docs/ar01s04.html \
		docs/ar01s05.html docs/ar01s06.html docs/ar01s07.html docs/ar01s08.html \
		docs/ar01s09.html docs/ar01s10.html docs/ar01s11.html docs/ar01s12.html

EX_CONFIGS=	cf.server.sample curses.cf.sample filter.pl.sample main.cf.sample \
		master.ignore.sample master.score.sample newsrc.sample

.if !defined(NOPORTDOCS)
post-install:
	${MKDIR} ${EXAMPLESDIR}
.for i in ${EX_CONFIGS}
	${INSTALL_DATA} ${WRKSRC}/sample_config/${i} ${EXAMPLESDIR}
.endfor
	${MKDIR} ${DOCSDIR}
.for i in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
