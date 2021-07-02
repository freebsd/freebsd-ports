# Created by: Stefan Esser <se@FreeBSD.org>

PORTNAME=	argus-clients
PORTVERSION=	3.0.8.3
CATEGORIES=	net-mgmt security
MASTER_SITES=	http://qosient.com/argus/src/ \
		ftp://qosient.com/pub/argus/src/

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Client programs for the argus IP network transaction auditing tool

LICENSE=	GPLv3

USES=		bison ncurses perl5 readline shebangfix
CONFLICTS=	argus-clients-2* argus-clients-sasl-2*

OPTIONS_DEFINE=	MYSQL SASL DOCS EXAMPLES
OPTIONS_DEFAULT=MYSQL SASL
OPTIONS_SUB=	yes
SASL_LIB_DEPENDS=	libsasl2.so:security/cyrus-sasl2
SASL_CONFIGURE_ON=	--with-sasl=${LOCALBASE}
MYSQL_USES=	mysql

GNU_CONFIGURE=	yes
SHEBANG_FILES=	examples/rahosts/raips.pl

# Fix build with clang11
CFLAGS+=	-fcommon

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MSASL}
PKGNAMESUFFIX+=	-sasl
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|/etc/radium.conf|${PREFIX}/etc/radium.conf|' ${WRKSRC}/clients/radium.c
	@${REINPLACE_CMD} -e 's|/usr/lib/sasl2|${PREFIX}/lib/sasl2|' ${WRKSRC}/common/argus_auth.c
	@${REINPLACE_CMD} -e 's|/etc/ra.conf|${PREFIX}/etc/ra.conf|' ${WRKSRC}/common/argus_util.c
	@${REINPLACE_CMD} -e 's|/etc/rapolicy.conf|${PREFIX}/etc/rapolicy.conf|' \
		${WRKSRC}/examples/rapolicy/rapolicy.c
	@${REINPLACE_CMD} -e 's|/usr/local/bin/ra|${PREFIX}/bin/ra|' \
		${WRKSRC}/examples/ramysql/rasql.c

do-install:
.for i in ra rabins racluster raconvert racount radium radump raevent \
	rafilteraddr ragrep rahisto ralabel ranonymize rapath rapolicy \
	rarpwatch raservices rasort rasplit rastream rastrip \
	ratemplate ratimerange ratop rauserdata
	${INSTALL_PROGRAM} ${WRKSRC}/bin/$i ${STAGEDIR}/${PREFIX}/bin/$i
.endfor
.for i in argusclientbug radark ragraph rahosts raips raplot raports
	${INSTALL_SCRIPT} ${WRKSRC}/bin/$i ${STAGEDIR}/${PREFIX}/bin/$i
.endfor
.for i in ra.1 rabins.1 racluster.1 raconvert.1 racount.1 radump.1 raevent.1 \
	rafilteraddr.1 ragraph.1 ragrep.1 rahisto.1 ralabel.1 ranonymize.1 \
	rapath.1 rapolicy.1 rasort.1 rasplit.1 rastream.1 rastrip.1
	${INSTALL_MAN} ${WRKSRC}/man/man1/$i ${STAGEDIR}/${PREFIX}/man/man1
.endfor
.for i in racluster.5 radium.conf.5 ralabel.conf.5 ranonymize.5 rarc.5
	${INSTALL_MAN} ${WRKSRC}/man/man5/$i ${STAGEDIR}/${PREFIX}/man/man5
.endfor
.for i in radium.8
	${INSTALL_MAN} ${WRKSRC}/man/man8/$i ${STAGEDIR}/${PREFIX}/man/man8
.endfor

do-install-MYSQL-on:
.for i in rasql rasqlinsert rasqltimeindex
	${INSTALL_PROGRAM} ${WRKSRC}/bin/$i ${STAGEDIR}/${PREFIX}/bin/$i
.endfor
.for i in rasql.1 rasqlinsert.1 rasqltimeindex.1
	${INSTALL_MAN} ${WRKSRC}/man/man1/$i ${STAGEDIR}/${PREFIX}/man/man1
.endfor

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}/${DOCSDIR}/
.for i in AUTHORS CHANGES CREDITS ChangeLog INSTALL \
	MANIFEST README VERSION
	${INSTALL_DATA} ${WRKSRC}/$i ${STAGEDIR}/${DOCSDIR}
.endfor

do-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}/${EXAMPLESDIR}
.for i in Config Database Startup System
	${MKDIR} ${STAGEDIR}/${EXAMPLESDIR}/$i
.endfor
.for i in delegated-ipv4-latest excel.rc iana-address-file \
	iana-ipv4-address iana-multicast-address iana-port-numbers \
	racluster.conf radium.conf ragetcountrycodes.sh ralabel.conf \
	ranonymize.conf rarc rarc.print.all.conf rastream.sh std.sig \
	wireshark.manuf.txt
	${INSTALL_DATA} ${WRKSRC}/support/Config/$i ${STAGEDIR}/${EXAMPLESDIR}/Config/$i
.endfor
.for i in MySQL.Archive.sh README
	${INSTALL_DATA} ${WRKSRC}/support/Database/$i ${STAGEDIR}/${EXAMPLESDIR}/Database/$i
.endfor
.for i in README com.qosient.radium.plist com.qosient.rasplit.plist \
	radium radium.service rasplit
	${INSTALL_DATA} ${WRKSRC}/support/Startup/$i ${STAGEDIR}/${EXAMPLESDIR}/Startup/$i
.endfor
.for i in magic
	${INSTALL_DATA} ${WRKSRC}/support/System/$i ${STAGEDIR}/${EXAMPLESDIR}/System/$i
.endfor
.include <bsd.port.mk>
