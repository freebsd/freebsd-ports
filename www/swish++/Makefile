# ex:ts=8
# Ports collection makefile for:	swish++
# Date created:			Jan 13, 2002
# Whom:              		ijliao
#
# $FreeBSD$
#

PORTNAME=	swish++
PORTVERSION=	5.6
CATEGORIES=	www textproc
MASTER_SITES=	http://homepage.mac.com/pauljlucas/software/

MAINTAINER=	ports@FreeBSD.org

RUN_DEPENDS=	wget:${PORTSDIR}/ftp/wget

USE_PERL5=	yes
USE_GMAKE=	yes
MAKEFILE=	GNUmakefile
MAKE_ENV=	PTHREAD_LIB=${PTHREAD_LIBS} \
		PERL=${PERL} PERL_VER=${PERL_VER}

MAN1=	extract.1 httpindex.1 index.1 search.1 splitmail.1
MAN3=	WWW.3
MAN4=	swish++.conf.4 swish++.index.4
MAN8=	searchd.8 searchmonitor.8

post-patch:
	@(cd ${WRKSRC} ; \
	  ${SED} '/^#error/d' config.h > config.h.tmp ; \
	  ${MV} -f config.h.tmp config.h)
.for file in searchd searchmonitor
	@${PERL} -pi -e "s,%%PREFIX%%,${PREFIX},g" ${WRKSRC}/${file}
.endfor

post-install:
	${INSTALL_SCRIPT} ${FILESDIR}/swish++.sh ${PREFIX}/etc/rc.d

.include <bsd.port.mk>
