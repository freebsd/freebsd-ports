# Created by: Stefan Esser <se@FreeBSD.org>
# $FreeBSD$

PORTNAME=	argus-clients
PORTVERSION=	3.0.6.2
CATEGORIES=	net-mgmt security
MASTER_SITES=	http://qosient.com/argus/src/ \
		ftp://qosient.com/pub/argus/src/

MAINTAINER=	pauls@utdallas.edu
COMMENT=	Client programs for the argus IP network transaction auditing tool

LICENSE=	GPLv3

CONFLICTS=	argus-clients-2* argus-clients-sasl-2*

OPTIONS_DEFINE=	GEOIP MANPAGES MYSQL SASL
OPTIONS_DEFAULT=MANPAGES MYSQL SASL

.include <bsd.port.options.mk>

USE_BISON=	build
GNU_CONFIGURE=	true
USE_NCURSES=	yes
USE_PERL5=	yes

.if ${PORT_OPTIONS:MSASL}
PKGNAMESUFFIX+=	-sasl
LIB_DEPENDS+=	sasl2:${PORTSDIR}/security/cyrus-sasl2
CONFIGURE_ARGS+=	--with-sasl=${LOCALBASE}
.endif

.if ${PORT_OPTIONS:MMYSQL}
USE_MYSQL=	yes
PLIST_SUB+=	MYSQL=""
MAN1+=		rasql.1 rasqlinsert.1 rasqltimeindex.1
.else
PLIST_SUB+=	MYSQL="@comment "
.endif

.if ${PORT_OPTIONS:MGEOIP}
LIB_DEPENDS+=	GeoIP:${PORTSDIR}/net/GeoIP
CONFIGURE_ARGS+=	--with-GeoIP=${LOCALBASE}
.endif

MAN1+=	ra.1 rabins.1 racluster.1 raconvert.1 racount.1 radump.1 raevent.1 \
	rafilteraddr.1 ragraph.1 ragrep.1 rahisto.1 ralabel.1 ranonymize.1 \
	rapath.1 rapolicy.1 rasort.1 rasplit.1 rastream.1 rastrip.1
MAN5=	racluster.5 radium.conf.5 ralabel.conf.5 ranonymize.5 rarc.5
MAN8=	radium.8

do-install:
.for i in ra rabins racluster raconvert racount radium radump raevent \
	rafilteraddr ragrep rahisto ralabel ranonymize rapath rapolicy \
	rarpwatch raservices rasort rasplit rastream rastrip \
	ratemplate ratimerange ratop rauserdata
	${INSTALL_PROGRAM} ${WRKSRC}/bin/$i ${PREFIX}/bin/$i
.endfor

.for i in argusclientbug radark ragraph rahosts raips raplot raports
	${INSTALL_SCRIPT} ${WRKSRC}/bin/$i ${PREFIX}/bin/$i
.endfor

.if ${PORT_OPTIONS:MMYSQL}
.for i in rasql rasqlinsert rasqltimeindex
	${INSTALL_PROGRAM} ${WRKSRC}/bin/$i ${PREFIX}/bin/$i
.endfor
.endif
.for i in radark ragraph rahosts raports
	${INSTALL_SCRIPT} ${WRKSRC}/bin/$i ${PREFIX}/bin/$i
.endfor
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}/
.for i in AUTHORS CHANGES CREDITS ChangeLog INSTALL \
	MANIFEST README VERSION
	${INSTALL_DATA} ${WRKSRC}/$i ${DOCSDIR}
.endfor
.endif
.if ${PORT_OPTIONS:MMANPAGES}
.for i in ${MAN1}
	${INSTALL_DATA} ${WRKSRC}/man/man1/$i ${MANPREFIX}/man/man1
.endfor
.for i in ${MAN5}
	${INSTALL_DATA} ${WRKSRC}/man/man5/$i ${MANPREFIX}/man/man5
.endfor
.for i in ${MAN8}
	${INSTALL_DATA} ${WRKSRC}/man/man8/$i ${MANPREFIX}/man/man8
.endfor
.endif
	${MKDIR} ${EXAMPLESDIR}
.for i in Config Database Startup System
	${MKDIR} ${EXAMPLESDIR}/$i
.endfor

.for i in delegated-ipv4-latest excel.rc iana-address-file \
	iana-ipv4-address iana-multicast-address iana-port-numbers \
	racluster.conf radium.conf ragetcountrycodes.sh ralabel.conf \
	ranonymize.conf rarc rarc.print.all.conf rastream.sh std.sig \
	wireshark.manuf.txt
	${INSTALL_DATA} ${WRKSRC}/support/Config/$i ${EXAMPLESDIR}/Config/$i
.endfor
.for i in MySQL.Archive.sh README
	${INSTALL_DATA} ${WRKSRC}/support/Database/$i ${EXAMPLESDIR}/Database/$i
.endfor
.for i in README com.qosient.radium.plist com.qosient.rasplit.plist \
	radium radium.service rasplit
	${INSTALL_DATA} ${WRKSRC}/support/Startup/$i ${EXAMPLESDIR}/Startup/$i
.endfor
.for i in magic
	${INSTALL_DATA} ${WRKSRC}/support/System/$i ${EXAMPLESDIR}/System/$i
.endfor
.include <bsd.port.mk>
