# New ports collection makefile for:    xymon-server
# Date created:         24 Jan 2008
# Whom:                 dirk.meyer@dinoex.sub.org
#
# $FreeBSD$
#

PORTNAME=	xymon
PORTVERSION=	4.2.3
PORTREVISION=	1
CATEGORIES=	net-mgmt www
MASTER_SITES=	SF/hobbitmon/hobbitserver/${PORTVERSION}
PKGNAMESUFFIX=	-server${PKGNAMESUFFIX2}

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	System for monitoring servers and networks

BUILD_DEPENDS=	rrdtool:${PORTSDIR}/databases/rrdtool
LIB_DEPENDS=	png:${PORTSDIR}/graphics/png \
		pcre:${PORTSDIR}/devel/pcre
RUN_DEPENDS=	rrdtool:${PORTSDIR}/databases/rrdtool

MAKE_JOBS_UNSAFE=	yes

# Options
BBUSER?=	hobbit
BBHOSTNAME?=	hobbit.example.com
BBHOSTIP?=	127.0.0.1

USE_GMAKE=	yes
USE_OPENSSL=	yes
CONFIGURE_ENV=	MAKE=gmake
MAKE_ENV+=	BBUSER="${BBUSER}"
MAKE_ENV+=	BBHOSTNAME="${BBHOSTNAME}"
MAKE_ENV+=	BBHOSTIP="${BBHOSTIP}"
USE_RC_SUBR=	hobbit-server.sh
SUB_LIST+=	BBUSER="${BBUSER}"
PLIST_SUB+=	BBUSER="${BBUSER}" VARBASE="/var"

CONFIG_FILES=	bb-hosts bb-services bbcombotest.cfg client-local.cfg \
		columndoc.csv hobbit-alerts.cfg hobbit-apache.conf \
		hobbit-clients.cfg hobbitcgi.cfg hobbitgraph.cfg \
		hobbitlaunch.cfg hobbitserver.cfg
FIXME1=	bb-hosts hobbit-alerts.cfg hobbit-clients.cfg bbcombotest.cfg

MAN1 =	bb-ack.cgi.1 bb-csvinfo.cgi.1 bb-datepage.cgi.1 bb-eventlog.cgi.1 \
	bb-findhost.cgi.1 bb-hist.cgi.1 bb-rep.cgi.1 bb-replog.cgi.1 \
	bb-snapshot.cgi.1 bb-webpage.cgi.1 bb.1 bbcmd.1 bbcombotest.1 bbdigest.1 \
	bbgen.1 bbhostgrep.1 bbhostshow.1 bbretest-net.sh.1 bbtest-net.1 \
	clientupdate.1 hobbit-ackinfo.cgi.1 hobbit-confreport.cgi.1 \
	hobbit-ghosts.cgi.1 hobbit-hostgraphs.cgi.1 hobbit-nkedit.cgi.1 \
	hobbit-nkview.cgi.1 hobbit-statusreport.cgi.1 hobbitgraph.cgi.1 \
	hobbitping.1 hobbitsvc.cgi.1 logfetch.1 orcahobbit.1
MAN5=	bb-hosts.5 bb-services.5 bbcombotest.cfg.5 client-local.cfg.5 \
	clientlaunch.cfg.5 hobbit-alerts.cfg.5 hobbit-clients.cfg.5 \
	hobbit-nkview.cfg.5 hobbitcgi.cfg.5 hobbitclient.cfg.5 \
	hobbitgraph.cfg.5 hobbitlaunch.cfg.5 hobbitserver.cfg.5 hobbitweb.5
MAN7=	xymon.7
MAN8=	bbmessage.cgi.8 bbproxy.8 hobbit-enadis.cgi.8 hobbit-mailack.8 \
	hobbitd.8 hobbitd_alert.8 hobbitd_channel.8 hobbitd_client.8 \
	hobbitd_filestore.8 hobbitd_history.8 hobbitd_hostdata.8 \
	hobbitd_rrd.8 hobbitd_sample.8 hobbitfetch.8 hobbitlaunch.8 \
	msgcache.8 trimhistory.8

.if defined(WITH_LDAP)
MAKE_ENV+=	WITH_LDAP=1
USE_OPENLDAP=	yes
.endif

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 700000
BROKEN=		does not compile on 6.X
.endif

# Configure script is interactive
do-configure:
	${CP} ${FILESDIR}/Makefile ${WRKSRC}/

pre-install:
	if ! pw groupshow ${BBUSER}; then pw groupadd ${BBUSER} -g 280; fi
	if ! pw usershow ${BBUSER}; then pw useradd ${BBUSER} -g ${BBUSER} -u 280 \
		-h - -d ${WWWDIR} -s /usr/sbin/nologin -c "Hobbit Monitor"; fi

post-install:
	-${MKDIR} ${WWWDIR}/server/etc
.for i in ${FIXME1}
	${INSTALL_DATA} ${WRKSRC}/hobbitd/etcfiles/${i} ${WWWDIR}/server/etc/${i}-dist
.endfor
.for i in ${CONFIG_FILES}
	${CP} -np ${WWWDIR}/server/etc/${i}-dist \
		${WWWDIR}/server/etc/${i}
.endfor

.include <bsd.port.post.mk>
