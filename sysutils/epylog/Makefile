# New ports collection makefile for:	epylog
# Date created:				3 July 2005
# Whom:					Alan Snelson <alan@wave2.co.uk>
#
# $FreeBSD$
#

PORTNAME=	epylog
PORTVERSION=	1.0.3
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	http://linux.duke.edu/projects/epylog/download/

MAINTAINER=	alan@wave2.co.uk
COMMENT=	Epylog is a syslog parser which mails you the output

BUILD_DEPENDS=	${PYTHON_SITELIBDIR}/libxml2.py:${PORTSDIR}/textproc/py-libxml2
RUN_DEPENDS=	${PYTHON_SITELIBDIR}/libxml2.py:${PORTSDIR}/textproc/py-libxml2 \
		lynx:${PORTSDIR}/www/lynx

MAN3=		epylog.3
MAN5=		epylog-modules.5 epylog.conf.5
MAN8=		epylog.8

USE_REINPLACE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-lynx=${LOCALBASE}/bin/lynx
USE_PERL5=	yes
USE_PYTHON=	yes

CONF_FILES=	epylog.conf \
		modules.d/logins.conf \
		modules.d/mail.conf \
		modules.d/notices.conf \
		modules.d/packets.conf \
		modules.d/spamd.conf \
		modules.d/weeder.conf \
		notice_local.xml \
		report_template.html \
		weed_local.cf

SUB_FILES=	pkg-install pkg-deinstall
SUB_LIST=	CONF_FILES="${CONF_FILES}"

post-patch:
	@${REINPLACE_CMD} -e 's|$$sysconfdir/cron\.daily|$$sysconfdir/epylog|' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|/var/log/secure|/var/log/auth.log|' \
		${WRKSRC}/etc/modules.d/logins.conf.in \
		${WRKSRC}/etc/modules.d/notices.conf.in \
		${WRKSRC}/etc/modules.d/weeder.conf.in

post-install:
	@PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

.include <bsd.port.mk>
