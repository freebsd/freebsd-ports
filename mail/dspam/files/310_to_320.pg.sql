/** dspam 3.1.0 to 3.2.0 pgsql migration script */

CREATE INDEX id_token_data_03 ON dspam_token_data(token);

CREATE TABLE dspam_signature_data_tmp (
  uid smallint,
  signature varchar(128),
  data bytea,
  length int,
  created_on date,
  UNIQUE (signature, uid)
);
INSERT INTO dspam_signature_data_tmp SELECT * FROM dspam_signature_data;
DROP TABLE dspam_signature_data;
ALTER TABLE dspam_signature_data_tmp RENAME TO dspam_signature_data;

CREATE TABLE dspam_neural_decisions_tmp (
  uid smallint,
  signature varchar(128),
  data bytea,
  length smallint,
  length int,
  created_on date,
  UNIQUE (signature, uid)
);
INSERT INTO dspam_neural_decisions_tmp SELECT * FROM dspam_neural_decisions;
DROP TABLE dspam_neural_decisions;
ALTER TABLE dspam_neural_decisions_tmp  RENAME TO dspam_neural_decisions;

CREATE TABLE dspam_preferences (
  uid smallint,
  preference varchar(128),
  value varchar(128),
  UNIQUE (preference, uid)
);
