--- buhg/sozsqlbaz.c.orig	Wed Oct  8 19:02:05 2003
+++ buhg/sozsqlbaz.c	Wed Oct  8 19:03:55 2003
@@ -363,7 +363,7 @@
 
 printw("Создание таблицы сальдо для счетов Saldo !\n");
 memset(strsql,'\0',sizeof(strsql));
-strcpy(strsql,"CREATE TABLE Saldo \(
+strcpy(strsql,"CREATE TABLE Saldo \( \
 kkk 	char(2) not null,\
 gs      smallint not null,\
 ns	char(20) not null references Plansh,\
@@ -1091,7 +1091,7 @@
 memset(strsql,'\0',sizeof(strsql));
 strcpy(strsql,"CREATE TABLE Uder (\
 kod	smallint not null primary key,\
-naik    varchar(60) not null,
+naik    varchar(60) not null,\
 shet    varchar(12) not null references Plansh (ns),\
 ktoz    smallint unsigned not null,\
 vrem    int unsigned not null,\
@@ -1141,7 +1141,7 @@
 memset(strsql,'\0',sizeof(strsql));
 strcpy(strsql,"CREATE TABLE Kateg (\
 kod	smallint not null primary key,\
-naik    varchar(60) not null,
+naik    varchar(60) not null,\
 ktoz    smallint unsigned not null,\
 vrem    int unsigned not null)");
 /*
@@ -1165,7 +1165,7 @@
 memset(strsql,'\0',sizeof(strsql));
 strcpy(strsql,"CREATE TABLE Zvan (\
 kod	smallint not null primary key,\
-naik    varchar(60) not null,
+naik    varchar(60) not null,\
 ktoz    smallint unsigned not null,\
 vrem    int unsigned not null)");
 /*
@@ -1213,7 +1213,7 @@
 memset(strsql,'\0',sizeof(strsql));
 strcpy(strsql,"CREATE TABLE Tabel (\
 kod	smallint not null primary key,\
-naik    varchar(60) not null,
+naik    varchar(60) not null,\
 ktoz    smallint unsigned not null,\
 vrem    int unsigned not null)");
 /*
@@ -1392,8 +1392,8 @@
 vrem    int unsigned not null,\
 kom	varchar(40) not null,\
 podr	int not null not null,\
-unique (datz,tabn,prn,knah,godn,mesn,podr,shet,nomz),
-index (tabn,datz),
+unique (datz,tabn,prn,knah,godn,mesn,podr,shet,nomz),\
+index (tabn,datz),\
 index tabn1 (tabn,godn,mesn))");
 
 /*
@@ -1550,8 +1550,8 @@
 datau  DATE not null,\
 lgota  char(4) not null,\
 ktoz   smallint unsigned not null,\
-vrem   int unsigned not null,
-fio    varchar(60) not null,
+vrem   int unsigned not null,\
+fio    varchar(60) not null,\
 unique(nomd,inn,priz,lgota))");
 
 /*
@@ -2455,7 +2455,7 @@
 sherez varchar(40) not null,\
 datop DATE not null,\
 nds smallint not null,\
-unique(datd,nomd),
+unique(datd,nomd),\
 index(nomnn))");
 /*
 0  datd	дата документа
@@ -2518,7 +2518,7 @@
 bsby	double(10,2) not null,\
 izby    double(10,2) not null,\
 cena	double(14,2) not null,\
-unique(datd,nomd,innom),
+unique(datd,nomd,innom),\
 index(innom,datd))");
 /*
 0  datd	  дата документа
@@ -3079,8 +3079,8 @@
 dokum   varchar(80) not null,\
 god     smallint not null,\
 ktoi    smallint unsigned not null,\
-vrem    int unsigned not null,
-unique(nomd,kassa,tp,god),
+vrem    int unsigned not null,\
+unique(nomd,kassa,tp,god),\
 index(datd,kassa))");
 
 /*
