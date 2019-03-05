# $FreeBSD$

PORTNAME?=logwatch
PREFIX?=/usr/local/${PORTNAME}
ETCDIR?=${PREFIX}/etc/${PORTNAME}
LIBDIR?=${PREFIX}/lib/${PORTNAME}
LIBEXECDIR?=${PREFIX}/libexec/${PORTNAME}
CACHEDIR?=${PREFIX}/var/${PORTNAME}
MANDIR?=${PREFIX}/man
MAN8DIR?=${MANDIR}/man8
SITE_PERL=	${PREFIX}/${SITE_PERL_REL}

all: logwatch

logwatch:
	@echo "There is no build target, only install."
	@echo "If you are not using FreeBSD ports,"
	@echo "please run, ./install_logwatch.sh after"
	@echo "reading the ./README file."

install:
	install -d $(DESTDIR)${PREFIX}/sbin
	install -d $(DESTDIR)${ETCDIR}/html
	install -d $(DESTDIR)${ETCDIR}/logfiles
	install -d $(DESTDIR)${ETCDIR}/services
	install -d $(DESTDIR)${ETCDIR}/defaults/html
	install -d $(DESTDIR)${ETCDIR}/defaults/logfiles
	install -d $(DESTDIR)${ETCDIR}/defaults/services
	install -d $(DESTDIR)${LIBEXECDIR}
	install -d $(DESTDIR)${SITE_PERL}
	install -d $(DESTDIR)${CACHEDIR}
	install -d $(DESTDIR)${MAN8DIR}
	install -m 555 scripts/logwatch.pl $(DESTDIR)${PREFIX}/sbin
	install -m 555 lib/Logwatch.pm $(DESTDIR)${SITE_PERL}
	install -m 444 logwatch.8 $(DESTDIR)${MAN8DIR}
	install -m 644 conf/logwatch.conf $(DESTDIR)${ETCDIR}/defaults
	install -m 640 conf/ignore.conf $(DESTDIR)${ETCDIR}/defaults
	install -m 444 conf/html/header.html $(DESTDIR)${ETCDIR}/defaults/html
	install -m 444 conf/html/footer.html $(DESTDIR)${ETCDIR}/defaults/html
.for etcdir in html logfiles services
	mkdir -p $(DESTDIR)${ETCDIR}/defaults/${etcdir}
.endfor
.for scriptdir in logfiles services shared
	mkdir -p $(DESTDIR)${LIBEXECDIR}/defaults/${scriptdir}
.endfor
.for logfile in \
	autorpm \
	bfd \
	cisco \
	clamav \
	clam-update \
	cron \
	daemon \
	denyhosts \
	dnssec \
	dovecot \
	dpkg \
	emerge \
	eventlog \
	exim \
	extreme-networks \
	fail2ban \
	http \
	http-error \
	iptables \
	kernel \
	maillog \
	messages \
	mysql \
	netopia \
	netscreen \
	php \
	pix \
	pureftp \
	qmail-pop3d-current \
	qmail-pop3ds-current \
	qmail-send-current \
	qmail-smtpd-current \
	resolver \
	rsnapshot \
	rt314 \
	samba \
	secure \
	sonicwall \
	spamassassin \
	syslog \
	tac_acc \
	up2date \
	vsftpd \
	windows \
	xferlog \
	yum
	install -m 640 conf/logfiles/${logfile}.conf $(DESTDIR)${ETCDIR}/defaults/logfiles/${logfile}.conf
.endfor
.for service in \
	afpd \
	amavis \
	arpwatch \
	audit \
	automount \
	autorpm \
	barracuda \
	bfd \
	cisco \
	clam-update \
	clamav \
	clamav-milter \
	courier \
	cron \
	denyhosts \
	dhcpd \
	dnssec \
	dovecot \
	dpkg \
	emerge \
	evtapplication \
	evtsecurity \
	evtsystem \
	exim \
	eximstats \
	extreme-networks \
	fail2ban \
	fetchmail \
	ftpd-messages \
	ftpd-xferlog \
	http \
	http-error \
	identd \
	imapd \
	in.qpopper \
	init \
	ipop3d \
	iptables \
	kernel \
	mailscanner \
	modprobe \
	mountd \
	mysql \
	named \
	netopia \
	netscreen \
	oidentd \
	openvpn \
	pam \
	pam_pwdb \
	pam_unix \
	php \
	pix \
	pluto \
	pop3 \
	portsentry \
	postfix \
	pound \
	proftpd-messages \
	pureftpd \
	qmail \
	qmail-pop3d \
	qmail-pop3ds \
	qmail-send \
	qmail-smtpd \
	raid \
	resolver \
	rsnapshot \
	rt314 \
	samba \
	saslauthd \
	scsi \
	secure \
	sendmail \
	sendmail-largeboxes \
	shaperd \
	slon \
	smartd \
	sonicwall \
	spamassassin \
	sshd \
	sshd2 \
	stunnel \
	sudo \
	syslogd \
	syslog-ng \
	tac_acc \
	up2date \
	vpopmail \
	vsftpd \
	windows \
	xntpd \
	yum \
	zz-disk_space \
	zz-network \
	zz-runtime \
	zz-sys \
	zz-zfs
	install -m 444 scripts/services/${service} $(DESTDIR)${LIBEXECDIR}/defaults/services/${service}
	install -m 444 conf/services/${service}.conf $(DESTDIR)${ETCDIR}/defaults/services/${service}.conf
.endfor
.for script in \
	applybinddate \
	applyeurodate \
	applyhttpdate \
	applystddate \
	applytaidate \
	applyusdate \
	eventlogonlyservice \
	eventlogremoveservice \
	expandrepeats \
	hosthash \
	hostlist \
	multiservice \
	onlycontains \
	onlyhost \
	onlyservice \
	remove \
	removeheaders \
	removeservice
	install -m 555 scripts/shared/${script} $(DESTDIR)${LIBEXECDIR}/defaults/shared/${script}
.endfor
.for logfile in autorpm cron emerge samba up2date xferlog yum
	mkdir -p $(DESTDIR)${LIBEXECDIR}/defaults/logfiles/${logfile}
	install -m 555 scripts/logfiles/${logfile}/applydate $(DESTDIR)${LIBEXECDIR}/defaults/logfiles/${logfile}
.endfor
.for logfile in samba up2date xferlog
	install -m 555 scripts/logfiles/${logfile}/removeheaders $(DESTDIR)${LIBEXECDIR}/defaults/logfiles/${logfile}
.endfor
