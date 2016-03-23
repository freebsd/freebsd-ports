# Created by: Dominique Goncalves <dominique.goncalves@gmail.com>
# $FreeBSD$

PORTNAME=	squidanalyzer
PORTVERSION=	6.5
DISTVERSIONPREFIX=	v
CATEGORIES=	www perl5

MAINTAINER=	dominique.goncalves@gmail.com
COMMENT=	Squid access log report generation tool

LICENSE=	GPLv3

USE_GITHUB=	yes
GH_ACCOUNT=	darold

MAKE_JOBS_UNSAFE=yes

USE_PERL5=	configure
USES=		perl5
CONFIGURE_ENV=	DESTDIR=${STAGEDIR} \
		LOGFILE=/var/log/squid3/access.log \
		BINDIR=${PREFIX}/bin \
		CONFDIR=${PREFIX}/etc/squidreport \
		HTMLDIR=${PREFIX}/www/squidreport \
		BASEURL=/squidreport \
		MANDIR=${PREFIX}/man/man3 \
		DOCDIR=${PREFIX}/share/doc/squidanalyzer \
		INSTALLDIRS=site
ETCDIR=		${PREFIX}/etc/squidreport
SUB_FILES=	pkg-message

CONF_FILES=	excluded included network-aliases \
		squidanalyzer.conf user-aliases

post-install:
.for file in ${CONF_FILES}
	@${MV} ${STAGEDIR}${ETCDIR}/${file} \
		${STAGEDIR}${ETCDIR}/${file}.sample
.endfor

.include <bsd.port.mk>
